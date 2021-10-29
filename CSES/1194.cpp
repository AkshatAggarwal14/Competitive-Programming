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

//! monster distance and man distance
const ll N = 1000;
ll n, m, sx = -1, sy = -1;
ll dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string dir = "RDLU";
char grid[N][N];
ll monster_d[N][N], d[N][N], p_dir[N][N];
queue<pair<ll, ll>> monsters, bfs;

bool valid(ll &x, ll &y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (grid[x][y] == '#') return false;
    return true;
};

void Solution() {
    cin >> n >> m;
    // input
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> grid[i][j];
            d[i][j] = monster_d[i][j] = p_dir[i][j] = -1;
            if (grid[i][j] == 'M') monsters.push({i, j}), monster_d[i][j] = 0;
            if (grid[i][j] == 'A') sx = i, sy = j;
        }
    }

    // multisource bfs for monsters
    while (!monsters.empty()) {
        ll xx = monsters.front().first, yy = monsters.front().second;
        monsters.pop();
        for (ll i = 0; i < 4; ++i) {
            ll _xx = xx + dx[i];
            ll _yy = yy + dy[i];
            if (!valid(_xx, _yy)) continue;
            if (monster_d[_xx][_yy] != -1) continue;
            monster_d[_xx][_yy] = monster_d[xx][yy] + 1;
            monsters.push({_xx, _yy});
        }
    }

    bfs.push({sx, sy});
    d[sx][sy] = 0;
    // bfs for person
    while (!bfs.empty()) {
        ll xx = bfs.front().first, yy = bfs.front().second;
        bfs.pop();
        for (ll i = 0; i < 4; ++i) {
            ll _xx = xx + dx[i];
            ll _yy = yy + dy[i];
            if (!valid(_xx, _yy)) continue;
            if (d[_xx][_yy] != -1) continue;
            d[_xx][_yy] = d[xx][yy] + 1;
            p_dir[_xx][_yy] = i;
            bfs.push({_xx, _yy});
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if ((d[i][j] < monster_d[i][j] && d[i][j] != -1 && monster_d[i][j] != -1) || (d[i][j] != -1 && monster_d[i][j] == -1)) {
                    string path = "";
                    ll t = p_dir[i][j];
                    while (t != -1) {
                        path += dir[p_dir[i][j]];
                        i -= dx[t], j -= dy[t];
                        t = p_dir[i][j];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n";
                    cout << sz(path) << '\n';
                    cout << path << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}