#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m;
int sz = 0;
bool visited[1010][1010];
char grid[1010][1010];

bool isValid(int x, int y) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= m) return false;
    if (x >= n) return false;
    if (grid[x][y] == '0') return false;
    return true;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    sz++;
    for (int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (isValid(X, Y)) {
            if (!visited[X][Y]) {
                dfs(X, Y);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                sz = 0;
                dfs(i, j);
                ans = max(ans, sz);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}