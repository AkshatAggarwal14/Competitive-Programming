#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
const ll INF = LLONG_MAX;

void Solution() {
    string a, b;
    cin >> a >> b;
    ll n;
    cin >> n;
    vector<vector<ll>> dist(26, vector<ll>(26, INF));
    for (ll i = 0; i < n; ++i) {
        char u, v;
        ll d;
        cin >> u >> v >> d;
        u -= 'a', v -= 'a';
        dist[u][v] = min(d, dist[u][v]);
    }
    for (ll i = 0; i < 26; ++i) dist[i][i] = 0;
    // Floyd Warshall to find all costs
    for (ll k = 0; k < 26; ++k) {
        for (ll i = 0; i < 26; ++i) {
            for (ll j = 0; j < 26; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if (sz(a) != sz(b)) return void(cout << -1 << '\n');
    ll ans = 0;
    string res = "";
    for (ll i = 0; i < sz(a); ++i) {
        ll cost = INF;
        char c = a[i];
        for (ll j = 0; j < 26; ++j) {
            if (dist[a[i] - 'a'][j] == INF || dist[b[i] - 'a'][j] == INF) continue;
            ll cost_ = dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j];
            if (cost_ < cost) {
                cost = cost_;
                c = char(j) + 'a';
            }
        }
        if (cost == INF) return void(cout << -1 << '\n');
        ans += cost;
        res += c;
    }
    cout << ans << '\n';
    cout << res << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}