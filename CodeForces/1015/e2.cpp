// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int;
auto sz = [](const auto &container) -> ll { return container.size(); };

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> mark(n, vector<bool>(m, false));
    for (auto &x : grid)
        for (auto &y : x) cin >> y;
    auto stars = [&](ll X, ll Y) -> ll {
        ll cnt = 1;
        //! checking all conditions in same for loop decreases execution time drastically as loop is stopped as soon as one condition fails
        for (; X - cnt >= 0 &&
               X + cnt < n &&
               Y - cnt >= 0 &&
               Y + cnt < m &&
               grid[X][Y + cnt] != '.' &&
               grid[X + cnt][Y] != '.' &&
               grid[X - cnt][Y] != '.' &&
               grid[X][Y - cnt] != '.';)
            ++cnt;
        return cnt - 1;
    };
    vector<array<ll, 3>> res;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                ll s = stars(i, j);
                if (s) {  // if size of star is > 0, add it and mark
                    mark[i][j] = true;
                    for (ll cnt = 1; cnt <= s; ++cnt) {
                        mark[i + cnt][j] = true;
                        mark[i - cnt][j] = true;
                        mark[i][j + cnt] = true;
                        mark[i][j - cnt] = true;
                    }
                    res.push_back({i, j, s});
                }
            }
        }
    }
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            if (grid[i][j] == '*' && !mark[i][j]) return cout << "-1\n", 0;
    cout << sz(res) << '\n';
    for (auto &[a, b, c] : res) cout << a + 1 << ' ' << b + 1 << ' ' << c << '\n';

    return 0;
}