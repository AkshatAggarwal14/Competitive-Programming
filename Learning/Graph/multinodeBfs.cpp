#include <bits/stdc++.h>
using namespace std;

// n,m
// 0 0 0 0 1 2
// 0 0 1 2 0 0

// 0 - empty, 1 - ripe, 2 - rotten

int n, m;
int a[1000][1000];
bool vis[1000][1000];

bool valid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (vis[x][y] || a[x][y] == 0) return false;  // if already visited or empty
    return true;
}

// graph moves - 4 directions
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // {x, y, distance}
    queue<array<int, 3>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                q.push({i, j, 0});  //distance 0 for rotten orange
                vis[i][j] = true;
            }
        }
    }

    int ans = 0;  // max distance of any code
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dis = q.front()[2];

        ans = max(ans, dis);

        q.pop();
        for (int i = 0; i < 4; ++i) {  // 4 directions
            int X = x + dx[i];
            int Y = y + dy[i];

            int newDis = dis + 1;
            if (valid(X, Y)) {
                vis[X][Y] = true;
                q.push({X, Y, newDis});
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
3 3
0 0 0
1 1 0
1 1 2
*/

// Output - 3

/*
4 4
0 1 1 1
2 1 0 1
1 2 1 1
0 0 0 1
*/

// Output - 4