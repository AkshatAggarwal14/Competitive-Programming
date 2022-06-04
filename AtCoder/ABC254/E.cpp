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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0, a, b; i < m; ++i) {
        cin >> a >> b, --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<ll> vis(n, false);
    queue<pair<ll, ll>> bfs;
    vector<ll> vis_id;
    ll sum = 0, k, q, x;
    cin >> q;
    while (q--) {
        cin >> x >> k, --x;

        bfs.push({x, 0});
        vis_id.push_back(x);
        vis[x] = true;
        while (!bfs.empty()) {
            auto par = bfs.front();
            bfs.pop();
            if (par.second > k) continue;
            sum += (par.first + 1);
            for (auto &it : g[par.first]) {
                if (vis[it]) continue;
                vis[it] = true;
                vis_id.push_back(it);
                bfs.push({it, par.second + 1});
            }
        }
        while (!vis_id.empty()) vis[vis_id.back()] = false, vis_id.pop_back();
        cout << sum << '\n';
        sum = 0;
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
