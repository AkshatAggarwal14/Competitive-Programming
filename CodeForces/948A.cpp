#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> vv(n + 2, vector<char>(m + 2, '.'));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> vv[i][j];
        }
    }
    auto isSafe = [&](ll x, ll y) {
        return !(vv[x][y + 1] == 'W' || vv[x + 1][y] == 'W' || vv[x - 1][y] == 'W' || vv[x][y - 1] == 'W');
    };

    bool check = true;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (vv[i][j] == 'S') {
                if (!isSafe(i, j)) check = false;
            }
        }
    }

    if (check) {
        cout << "Yes\n";
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                if (vv[i][j] == '.') vv[i][j] = 'D';  // set every . to D
                cout << vv[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}