#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e9;
template <class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> slow(n);
    for (auto &x : slow) cin >> x;

    vector<vector<ll>> dp(n, vector<ll>(n, INF));  // ith node, jth bike
    minpq<array<ll, 3>> pq;                        // {d, node, bike}

    dp[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [dist, node, bike] = pq.top();
        pq.pop();

        for (auto [child, wt] : g[node]) {
            // go with same bike
            if (dp[child][bike] > dist + slow[bike] * wt) {
                dp[child][bike] = dist + slow[bike] * wt;
                pq.push({dp[child][bike], child, bike});
            }
            // buy new bike
            if (dp[child][child] > dist + slow[bike] * wt) {
                dp[child][child] = dist + slow[bike] * wt;
                pq.push({dp[child][child], child, child});
            }
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
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
