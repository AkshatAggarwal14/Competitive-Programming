//Q1. Can we reach from A to B?
#include "bits/stdc++.h"
using namespace std;

//! Q1 - without graphs
// to check path use find_path(sx,sy,ex,ey)
/*
int n, m;
bool visited[1010][1010];
bool blocked[1010][1010];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    if (y < 0) return false;
    if (x < 0) return false;
    if (y >= m) return false;
    if (x >= n) return false;
    if (grid[x][y] == '#' || visited[x][y]) return false;
    return true;
}

//? checks path from (x,y) to (ex,ey)
bool find_path(int x, int y, int ex, int ey) {
    if (!isValid(x, y)) return false;
    visited[x][y] = true;
    if (x == ex && y == ey) return true;  // already reached
    bool found = false;
    for (int i = 0; i < 4; i++) {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (find_path(X, Y, ex, ey)) found = true;
    }
    return found;
}
*/

//! using graphs
#include "bits/stdc++.h"
using namespace std;

int n, m;
bool visited[1010];
vector<int> adj[1010];

bool find_path(int curr, int destination) {
    if (curr == destination) return true;
    visited[curr] = true;
    bool found = false;
    for (int vertex : adj[curr]) {
        if (visited[vertex]) continue;
        if (find_path(vertex, destination)) found = true;
    }
    return found;
}

void Solution() {
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}