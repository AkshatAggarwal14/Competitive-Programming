#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<pair<int, int>> edges(n);
    bool flag = false;
    vector<ll> deg(n, 0);
    vector<vector<int>> g(n);
    for (auto &[a, b] : edges) {
        cin >> a >> b, --a, --b;
        if (a == b) flag = true;
        g[a].push_back(b);
        g[b].push_back(a);
        ++deg[a], ++deg[b];
        if (deg[a] > 2 || deg[b] > 2) flag = true;
    }
    if (flag) return void(cout << "NO\n");
    auto bipartite = [&]() {
        vector<ll> col(n, -1);
        queue<pair<ll, ll>> q;
        for (ll i = 0; i < n; i++) {
            if (col[i] == -1) {
                q.push({i, 0});
                col[i] = 0;
                while (!q.empty()) {
                    pair<ll, ll> p = q.front();
                    q.pop();
                    ll v = p.first;
                    ll c = p.second;
                    for (ll j : g[v]) {
                        if (col[j] == c) return false;
                        if (col[j] == -1) {
                            col[j] = (c) ? 0 : 1;
                            q.push({j, col[j]});
                        }
                    }
                }
            }
        }
        return true;
    };
    // bipartite are 2 colorable
    if (!bipartite()) return void(cout << "NO\n");
    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
