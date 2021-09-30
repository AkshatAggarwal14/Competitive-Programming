#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<bool>> vis;

bool valid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (vis[x][y]) return false;
    if (a[x][y] == 1) return false;
    return true;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

/*
The problem states positions are given as
(x y) => (horizontal_index vertical_index), hence will be used as [y][x]
*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n, vector<int>(m, 0));
    vis.resize(n, vector<bool>(m, false));
    // 2 - people infected
    // 0 - susceptible
    // 1 - vaccinated
    int A;
    cin >> A;
    for (int i = 0; i < A; ++i) {
        int X, Y;
        cin >> X >> Y;
        a[Y][X] = 2;
    }
    int V;
    cin >> V;
    for (int i = 0; i < V; ++i) {
        int X, Y;
        cin >> X >> Y;
        a[Y][X] = 1;
    }

    // {x, y}
    queue<array<int, 2>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }
    // Visit all Nodes using BFS - FASTER THAN DFS
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        for (int i = 0; i < 4; ++i) {  // 4 directions
            int X = x + dx[i];
            int Y = y + dy[i];
            if (valid(X, Y)) {
                vis[X][Y] = true;
                q.push({X, Y});
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && vis[i][j] == false) cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}