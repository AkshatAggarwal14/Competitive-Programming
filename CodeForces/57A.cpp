// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

// graph moves - 4 directions
ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};
ll n;
vector<vector<ll>> dis;
bool valid(ll x, ll y) {
    if (x < 0 || y < 0 || x > n || y > n) return false;
    if (dis[x][y] != 1e9) return false;             // already visited
    return (x == 0 || y == 0 || x == n || y == n);  // must be on border
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    dis.resize(n + 1, vector<ll>(n + 1, 1e9));  // distance + visited
    queue<pair<ll, ll>> bfs;
    bfs.emplace(x1, y1);
    dis[x1][y1] = 0;
    ll x, y, X, Y;
    while (!bfs.empty()) {
        x = bfs.front().first;
        y = bfs.front().second;
        bfs.pop();
        if (x == x2 && y == y2) break;
        for (ll i = 0; i < 4; ++i) {  // 4 directions
            X = x + dx[i];
            Y = y + dy[i];
            if (valid(X, Y)) {
                bfs.emplace(X, Y);
                dis[X][Y] = dis[x][y] + 1;
            }
        }
    }
    cout << dis[x2][y2] << '\n';
    return 0;
}