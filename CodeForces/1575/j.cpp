// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int;

void Solution() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n, vector<char>(m));
    for (auto &x : grid)
        for (auto &y : x) cin >> y;
    ll dx[] = {0, 1, 0}, dy[] = {1, 0, -1};
    // function<void(ll, ll)> dfs = [&](ll x, ll y) {
    //     if (x == n) return void(cout << y + 1 << ' ');
    //     ll t = grid[x][y] - '0';
    //     grid[x][y] = '2';
    //     dfs(x + dx[t - 1], y + dy[t - 1]);
    // };
    for (ll i = 0; i < k; ++i) {
        ll y, x = 0;
        cin >> y;
        --y;
        while (x < n) {
            ll t = grid[x][y] - '0';
            grid[x][y] = '2';
            x += dx[t - 1];
            y += dy[t - 1];
        }
        cout << y + 1 << ' ';
        // dfs(0, y - 1);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    Solution();
    return 0;
}