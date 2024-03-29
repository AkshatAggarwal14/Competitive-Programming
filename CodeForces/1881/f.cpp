#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const int INF = 1e9;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, k;
    cin >> n >> k;
    vector<int> mark(n + 1, false);
    for (int i = 0, u; i < k; ++i) {
        cin >> u;
        mark[u] = true;
    }

    vector<vector<int>> tree(n + 1);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> sub(n + 1, -INF);
    function<void(int, int)> dfsSubtree = [&](int node, int par) {
        if (mark[node]) {
            sub[node] = 0;
        }
        for (auto &child : tree[node]) {
            if (child != par) {
                dfsSubtree(child, node);
                sub[node] = max(sub[node], 1 + sub[child]);
            }
        }
    };

    dfsSubtree(1, 0);

    vector<int> ans(n + 1), up(n + 1, -INF);

    function<void(int, int)> dfsReroot = [&](int node, int par) {
        if (mark[node]) {
            up[node] = max(up[node], 0);
        }

        multiset<int> st;
        for (int &child : tree[node]) {
            if (child != par) {
                st.insert(sub[child]);
            }
        }

        for (int &child : tree[node]) {
            if (child != par) {
                st.erase(st.find(sub[child]));

                int maxi = -INF;
                if (!st.empty()) maxi = *st.rbegin();

                up[child] = max({up[child], 1 + up[node], maxi});
                if (maxi >= 0) {
                    up[child] = max(up[child], 2 + maxi);
                }

                st.insert(sub[child]);

                dfsReroot(child, node);
            }
        }

        ans[node] = max(up[node], sub[node]);
    };
    dfsReroot(1, 0);

    cout << *min_element(1 + ans.begin(), ans.end()) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
