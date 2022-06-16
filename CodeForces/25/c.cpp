#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()

void Solution() {
    ll n;
    cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < n; ++j) cin >> d[i][j];
    ll k;
    cin >> k;  // edges added
    for (ll p = 0; p < k; ++p) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        // updating current edge
        d[u][v] = min(d[u][v], w);
        d[v][u] = d[u][v];
        /*
        3 cases: 
        
        1. Either d[i][j] remains same                      // i -> j
        2. d[i][u] + d[u][v] + d[v][j] is less than d[i][j] // i -> u -> v -> j
        3. d[i][v] + d[u][v] + d[u][j] is less than d[i][j] // i -> v -> u -> j
        */
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < n; ++j)
                d[i][j] = min({d[i][j], d[i][u] + d[u][v] + d[v][j], d[i][v] + d[u][v] + d[u][j]});
        ll q = 0;
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < i; ++j) q += d[i][j];
        cout << q << ' ';
    }
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}