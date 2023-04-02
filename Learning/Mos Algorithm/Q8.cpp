// https://codeforces.com/contest/221/problem/D
// Mo's + compression
// WAIT! This doesnt even need compression as values greater than MAXN can never have count equal to them.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TODO: Find optimal block_size for compiler optimization
const int block_size = 317;  // sqrt(N)
// TODO: Define constants needed for global variables (arrays etc. - The DS)
const int N = 1e5 + 5;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
int a[N], cnt[N];
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

// TODO: add value at idx from data structure
// number x occurs exactly x times
void add(int idx) {
    if (a[idx] >= N) return;
    if (cnt[a[idx]] == a[idx]) --ans;
    ++cnt[a[idx]];
    if (cnt[a[idx]] == a[idx]) ++ans;
}

// TODO: remove value at idx from data structure
void remove(int idx) {
    if (a[idx] >= N) return;
    if (cnt[a[idx]] == a[idx]) --ans;
    --cnt[a[idx]];
    if (cnt[a[idx]] == a[idx]) ++ans;
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

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];

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