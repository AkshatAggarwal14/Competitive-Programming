#include "bits/stdc++.h"
using namespace std;

pair<int, int> blank = {-1, -1};

bool isValid(int &x, int &y, int &n, int &m, vector<vector<char>> &mat, vector<vector<pair<int, int>>> &parent) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (mat[x][y] == '#') return false;       // blocked
    if (parent[x][y] != blank) return false;  // already visited so has a parent added
    return true;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char dir[] = {'D', 'R', 'U', 'L'};

void Solution() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<int>> turn(n, vector<int>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, blank));

    int source_x = 0, source_y = 0, dest_x = 0, dest_y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') source_x = i, source_y = j;
            if (mat[i][j] == 'B') dest_x = i, dest_y = j;
        }
    }
    queue<pair<int, int>> q;
    q.push({source_x, source_y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //! Break BFS on finding destination (to make it FASTER)
        if (mat[x][y] == 'B') break;
        // Move from parents to children
        for (int i = 0; i < 4; ++i) {  // 4 directions
            int X = x + dx[i];
            int Y = y + dy[i];
            if (isValid(X, Y, n, m, mat, parent)) {
                q.push({X, Y});
                parent[X][Y] = make_pair(x, y);
                turn[X][Y] = i;  // stores index for D R U L
            }
        }
    }
    int ctr = 0;
    string route;
    pair<int, int> b = {dest_x, dest_y};
    pair<int, int> a = {source_x, source_y};
    while (parent[b.first][b.second] != blank && b != a) {
        route.push_back(dir[turn[b.first][b.second]]);  // get char from stores idx
        b = parent[b.first][b.second];
        ctr++;
    }
    if (b != a) return void(cout << "NO\n");
    cout << "YES\n";
    reverse(route.begin(), route.end());
    cout << ctr << '\n';
    cout << route << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}