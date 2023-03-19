#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, a, b, x, y;
    string start;
    cin >> n >> m >> a >> b >> x >> y >> start;

    int dx = -1;
    if (start[0] == 'D') dx = 1;
    int dy = -1;
    if (start[1] == 'R') dy = 1;

    map<array<int, 4>, int> vis;  // stores bounces for [x][y][dx][dy]
    queue<array<int, 4>> bfs;
    bfs.push({a, b, dx, dy});
    vis[{a, b, dx, dy}] = 0;

    while (!bfs.empty()) {
        auto [X, Y, dirx, diry] = bfs.front();
        bfs.pop();

        int nx = X + dirx, ny = Y + diry, ndirx = dirx, ndiry = diry;
        int cnt = 0;
        if (nx < 1 || nx > n) ndirx = -dirx, cnt = 1;
        if (ny < 1 || ny > m) ndiry = -diry, cnt = 1;
        nx = X + ndirx, ny = Y + ndiry;

        if (!vis.count({nx, ny, ndirx, ndiry})) {
            vis[{nx, ny, ndirx, ndiry}] = vis[{X, Y, dirx, diry}] + cnt;
            bfs.push({nx, ny, ndirx, ndiry});
        }
    }

    int ans = INT_MAX;
    for (auto i : {-1, 1}) {
        for (auto j : {-1, 1}) {
            if (vis.count({x, y, i, j})) {
                ans = min(ans, vis[{x, y, i, j}]);
            }
        }
    }

    cout << ((ans == INT_MAX) ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}