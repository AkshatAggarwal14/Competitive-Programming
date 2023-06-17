// Question: https://codeforces.com/problemset/problem/375/D
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int block_size = 317;  // sqrt(N) or N/sqrt(Q)
const int N = 1e5 + 5;

int col[N], cnt[N], euler[N], ans[N];

struct Query {
    int l, r, idx, k;
    Query() = default;
    Query(int L, int R, int i, int k_) : l(L), r(R), idx(i), k(k_) {}
    bool operator<(const Query &other) const {
        if (l / block_size != other.l / block_size) return l < other.l;
        return ((l / block_size) & 1) ? r < other.r : r > other.r;
    }
};

void add(int idx) {
    ++cnt[euler[idx]];
    ++ans[cnt[euler[idx]]];
}

void remove(int idx) {
    --ans[cnt[euler[idx]]];
    --cnt[euler[idx]];
}

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
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
        answers[q.idx] = ans[q.k];
    }
    return answers;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Euler tour: https://usaco.guide/gold/tree-euler?lang=cpp
    // Euler tour code: https://cses.fi/problemset/result/4320399/
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> col[i];
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int pos = 0;
    vector<int> first(n), last(n);
    auto dfs = [&](const auto &self, int node = 0, int parent = -1) -> void {
        first[node] = pos;
        for (int neighbor : g[node])
            if (neighbor != parent)
                self(self, neighbor, node);
        euler[pos++] = col[node];  // set color of node in euler tour
        last[node] = pos - 1;
    };
    dfs(dfs);

    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k, --v;
        queries[i] = {first[v], last[v], i, k};
    }

    /*
        Now we have an array euler[i], which contains integers, and problem is reduced to answer following queries: [l, r, k]
        answer to query is the number of elements in the range [l, r] that have a count greater than k.
        mo_s algo maintains the count of elements in the range [l, r]

    ANS: https://codeforces.com/blog/entry/53164
        ans[i] = number of elements with frequency atleast i
        cnt[i] = frequency of element i

        When you add an element x, ++cnt[x], ++ans[cnt[x]];

        When you delete an element, --ans[cnt[x]], --cnt[x];

        Answer for a query = ans[k]

    EXPLANATION:
        After you add +1 to cnt[x], it means that there is one more number now equal to or larger than ans[cnt[x]], so you just ++ans[cnt[x]]. When cnt[x] decreases, there no longer will be that number, so he is doing --ans[cnt[x]] before decreasing.
    */

    vector<ll> res = mo_s_algorithm(queries);
    for (auto &x : res)
        cout << x << '\n';
    return 0;
}
