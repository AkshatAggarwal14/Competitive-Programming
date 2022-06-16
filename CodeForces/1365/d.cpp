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

//! block all bad and then check path
void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    auto valid = [&](ll x, ll y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (vis[x][y] || mat[x][y] == '#') return false;
        return true;
    };
    auto dfs = [&](const auto &self, ll ex, ll ey) -> void {
        vis[ex][ey] = 1;
        for (ll k = 0; k < 4; ++k) {
            ll ni = ex + dx[k], nj = ey + dy[k];
            if (!valid(ni, nj)) continue;
            self(self, ni, nj);
        }
    };

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mat[i][j] == 'B') {
                for (ll k = 0; k < 4; ++k) {
                    ll ni = i + dx[k], nj = j + dy[k];
                    if (valid(ni, nj)) {
                        if (mat[ni][nj] == 'G') {  // adjacent 'G' and 'B'
                            return void(cout << "No\n");
                        } else if (mat[ni][nj] == 'B') {
                            continue;
                        } else {
                            mat[ni][nj] = '#';  // block '.' around 'B'
                        }
                    }
                }
            }
        }
    }
    // now check if path from (n,m) to every 'G' if (n,m) isnt blocked
    if (valid(n - 1, m - 1)) dfs(dfs, n - 1, m - 1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mat[i][j] == 'G' && vis[i][j] == 0) {
                return void(cout << "No\n");
            }
        }
    }
    cout << "Yes\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}