#include "bits/stdc++.h"
using namespace std;

bool isValid(int &x, int &y, int &n, int &m, vector<vector<char>> &mat, vector<vector<char>> &vis) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (mat[x][y] == '#') return false;  // blocked
    if (vis[x][y] != '*') return false;  //already visited
    return true;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<char> dir = {'D', 'R', 'U', 'L'};

void Solution() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<char>> vis(n, vector<char>(m, '*'));

    int source_x = 0, source_y = 0, dest_x = 0, dest_y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'A') source_x = i, source_y = j, mat[i][j] = '.';
            if (mat[i][j] == 'B') dest_x = i, dest_y = j, mat[i][j] = '.';
        }
    }

    bool connected = false;
    pair<int, int> b = {dest_x, dest_y};
    pair<int, int> a = {source_x, source_y};

    queue<pair<int, int>> q;
    q.push({source_x, source_y});
    vis[source_x][source_y] = '#';
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //! Break BFS on finding destination (to make it FASTER)
        if (x == dest_x && y == dest_y) {
            connected = true;
            break;
        }
        // Move from parents to children
        for (int i = 0; i < 4; ++i) {  // 4 directions
            int X = x + dx[i];
            int Y = y + dy[i];
            if (isValid(X, Y, n, m, mat, vis)) {
                q.push({X, Y});
                vis[X][Y] = dir[i];
            }
        }
    }
    if (!connected) return void(cout << "NO\n");
    string ans;
    while (b != a) {
        int x = b.first;
        int y = b.second;
        for (int i = 0; i < 4; ++i) {
            if (vis[x][y] == dir[i]) {
                ans.push_back(dir[i]);
                x -= dx[i];
                y -= dy[i];
                break;
            }
        }
        b = make_pair(x, y);
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    cout << ans.length() << '\n';
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}