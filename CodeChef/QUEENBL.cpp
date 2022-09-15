#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int x, y;
    cin >> x >> y;
    auto valid = [&](int X, int Y) {
        return (X >= 0 && X <= 7 && Y >= 0 && Y <= 7);
    };
    vector<string> grid(8, string(8, '0'));
    --x, --y;
    grid[x][y] = '1';
    if (x == 0 && y == 0) {
        grid[2][1] = '2';
    } else if (x == 7 && y == 0) {
        grid[5][1] = '2';
    } else if (x == 0 && y == 7) {
        grid[2][6] = '2';
    } else if (x == 7 && y == 7) {
        grid[5][6] = '2';
    } else if (x == 0) {
        grid[2][y - 1] = grid[2][y + 1] = '2';
    } else if (x == 7) {
        grid[5][y - 1] = grid[5][y + 1] = '2';
    } else if (y == 0) {
        grid[x - 1][2] = grid[x + 1][2] = '2';
    } else if (y == 7) {
        grid[x - 1][5] = grid[x + 1][5] = '2';
    } else {
        bool check = false;
        vector<vector<array<int, 2>>> choices;
        choices = {
            {{-2, 1}, {2, -1}},
            {{-2, -1}, {2, 1}},
            {{-1, 2}, {1, -2}},
            {{1, 2}, {-1, -2}}};
        for (auto &choice : choices) {
            int nx1 = x + choice[0][0], ny1 = y + choice[0][1];
            int nx2 = x + choice[1][0], ny2 = y + choice[1][1];
            if (valid(nx1, ny1) && valid(nx2, ny2)) {
                grid[nx1][ny1] = grid[nx2][ny2] = '2';
                check = true;
                break;
            }
        }
        if (!check) {
            if (x == 1 && y == 1) {
                grid[3][0] = grid[0][4] = '2';
            } else if (x == 1 && y == 6) {
                grid[3][7] = grid[0][3] = '2';
            } else if (x == 6 && y == 1) {
                grid[4][0] = grid[7][4] = '2';
            } else if (y == 6 && x == 6) {
                grid[4][7] = grid[7][3] = '2';
            }
        }
    }
    int queens = 0;
    for (auto &r : grid) {
        for (auto &c : r) {
            cout << c << ' ';
            queens += (c == '2');
        }
        cout << '\n';
    }
    assert(queens <= 3);
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
