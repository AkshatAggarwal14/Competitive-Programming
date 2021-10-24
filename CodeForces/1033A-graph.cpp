#include "bits/stdc++.h"
using namespace std;

//! Q1 - without graphs
// to check path use find_path(sx,sy,ex,ey)
int n;
bool visited[1010][1010];
bool blocked[1010][1010];
int grid[1010][1010];

array<int, 8> dx = {0, -1, 1, 0, -1, 1, 1, -1};
array<int, 8> dy = {1, 1, 1, -1, -1, -1, 0, 0};

bool isValid(int x, int y) {
    if (x <= 0 || y <= 0) return false;
    if (x > n || y > n) return false;
    if (blocked[x][y] || visited[x][y]) return false;
    return true;
}

//? checks path from (x,y) to (ex,ey)
bool find_path(int x, int y, int ex, int ey) {
    if (!isValid(x, y)) return false;
    visited[x][y] = true;
    if (x == ex && y == ey) return true;  // already reached
    bool found = false;
    for (int i = 0; i < 8; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (find_path(X, Y, ex, ey)) found = true;
    }
    return found;
}

int main() {
    cin >> n;
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    // Mark relevant places as blocked
    blocked[ax][ay] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 8; ++j) {
            int nx = ax + i * dx[j];
            int ny = ay + i * dy[j];
            if (isValid(nx, ny)) {
                blocked[nx][ny] = true;
            }
        }
    }

    if (find_path(bx, by, cx, cy))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}