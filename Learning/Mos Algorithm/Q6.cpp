// https://cses.fi/problemset/task/1734 - DQUERY with array compression
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TODO: Find optimal block_size for compiler optimization
const int block_size = 450;  // sqrt(N)
// TODO: Define constants needed for global variables (arrays etc. - The DS)
const int N = 2e5 + 5;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
int a[N], cnt[N];
int ans;

struct Query {
    int l, r, idx;
    Query() = default;
    Query(int L, int R, int i) : l(L), r(R), idx(i) {}
    pair<int, int> toPair() const {
        return make_pair(l / block_size, ((l / block_size) & 1) ? -r : +r);
    }
    bool operator<(const Query &other) const {
        return this->toPair() < other.toPair();
    }
};

// TODO: remove value at idx from data structure
void add(int idx) {
    if (cnt[a[idx]] == 0) ++ans;
    ++cnt[a[idx]];
}

// TODO: add value at idx from data structure
void remove(int idx) {
    --cnt[a[idx]];
    if (cnt[a[idx]] == 0) --ans;
}

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = ans;
    }
    return answers;
}

void coordinateCompress(int n) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {a[i], i};
    sort(v.begin(), v.end());
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || v[i].first != v[i - 1].first) {
            ++curr;
        }
        a[v[i].second] = curr;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ans = 0;
    memset(cnt, 0, sizeof(cnt));

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];

    coordinateCompress(n);

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i};
    }
    vector<int> res = mo_s_algorithm(queries);
    for (auto &x : res)
        cout << x << '\n';
}