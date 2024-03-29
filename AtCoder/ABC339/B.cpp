#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

void test() {
    ll H, W, N;
    cin >> H >> W >> N;

    vector<vector<char>> grid(H, vector<char>(W, '.'));

    ll dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    ll dir = 3;
    ll i = 0, j = 0;
    while (N--) {
        if (grid[i][j] == '.') {
            dir = dir + 1;
            if (dir == 4) dir = 0;

            grid[i][j] = '#';

        } else {
            dir = dir - 1;
            if (dir == -1) dir = 3;

            grid[i][j] = '.';
        }

        ll ni = i + dx[dir], nj = j + dy[dir];
        if (ni == H) ni = 0;
        if (ni == -1) ni = H - 1;
        if (nj == W) nj = 0;
        if (nj == -1) nj = W - 1;
        i = ni, j = nj;
    }

    for (auto &row : grid) {
        for (auto &cell : row) {
            cout << cell;
        }
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
