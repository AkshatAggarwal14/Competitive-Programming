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
    ll n, m, q, j1, j2;
    cin >> n >> m;
    vector<string> grid(n);
    for (ll i = 0; i < n; i++) cin >> grid[i];
    vector<ll> pref(m, 0);
    for (ll i = 1; i < n; i++)
        for (ll j = 1; j < m; j++)
            if (grid[i - 1][j] == 'X' && grid[i][j - 1] == 'X')  // these create problem
                pref[j] = 1;
    for (ll j = 1; j < m; j++) pref[j] += pref[j - 1];
    cin >> q;
    while (q--) {
        cin >> j1 >> j2;
        j1--;
        j2--;
        cout << (pref[j2] == pref[j1] ? "YES\n" : "NO\n");
    }
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