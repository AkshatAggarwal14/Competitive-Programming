#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<string> vv(h);
    for (ll i = 0; i < h; ++i) cin >> vv[i];
    x--, y--;
    if (vv[x][y] == '#') return void(cout << 0 << '\n');
    ll ans = 1;
    for (ll i = y + 1; i < w && vv[x][i] != '#'; ++i) ans++;
    for (ll i = y - 1; i >= 0 && vv[x][i] != '#'; --i) ans++;
    for (ll i = x + 1; i < h && vv[i][y] != '#'; ++i) ans++;
    for (ll i = x - 1; i >= 0 && vv[i][y] != '#'; --i) ans++;
    cout << ans << '\n';
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