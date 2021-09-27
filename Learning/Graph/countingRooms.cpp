//https://cses.fi/problemset/task/1192
#include "bits/stdc++.h"
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
bool visited[1010][1010];
char grid[1010][1010];

bool isValid(int x, int y) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= m) return false;
    if (x >= n) return false;
    if (grid[x][y] == '#') return false;
    return true;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (isValid(X, Y)) {
            if (!visited[X][Y]) {
                dfs(X, Y);
            }
        }
    }
}

void Solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }
    int components = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                components++;
            }
        }
    }
    cout << components;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}