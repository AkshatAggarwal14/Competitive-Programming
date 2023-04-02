// https://www.spoj.com/problems/DQUERY/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TODO: Find optimal block_size for compiler optimization
const int block_size = 70;  // N / sqrt(Q)
// TODO: Define constants needed for global variables (arrays etc. - The DS)
const int N = 30005;
const int MX = 1E6 + 5;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
int a[N], cnt[MX];
int ans;

struct Query {
    int l, r, idx;
    Query() = default;
    Query(int L, int R, int i) : l(L), r(R), idx(i) {}
    bool operator<(const Query &other) const {
        if (l / block_size != other.l / block_size) return l < other.l;
        return ((l / block_size) & 1) ? r < other.r : r > other.r;
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ans = 0;
    memset(cnt, 0, sizeof(cnt));

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    int q;
    cin >> q;
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