#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

// rotate grid
void rotate_grid(vector<string> &grid) {
    vector<string> mat(4, string(4, '.'));
    for (int j = 0, a = 0; j < 4; j++, a++)
        for (int i = 3, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
}

// fix a piece to top
vector<string> fixToTop(vector<string> &grid) {
    vector<string> res;
    int row = 4, col = 4, rm = -1, cm = -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == '#') {
                row = min(row, i);
                col = min(col, j);
                rm = max(rm, i);
                cm = max(cm, j);
            }
        }
    }
    // get only piece
    for (int i = row; i <= rm; ++i) {
        res.emplace_back();
        for (int j = col; j <= cm; ++j) {
            res.back().push_back(grid[i][j]);
        }
    }
    return res;
}

// O(16^3 * 4^3 * 4^2)
// O(4^11) = O(2^22) = O(4e6)
void test() {
    vector<vector<string>> grids(3, vector<string>(4));
    for (auto &grid : grids) {
        for (auto &row : grid) {
            cin >> row;
        }
    }
    vector<vector<vector<string>>> configs(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            configs[i].push_back(fixToTop(grids[i]));
            rotate_grid(grids[i]);
        }
    }
    // get all coordinate combinations
    for (int c1 = 0; c1 < 16; ++c1) {
        for (int c2 = 0; c2 < 16; ++c2) {
            for (int c3 = 0; c3 < 16; ++c3) {
                int i1 = c1 / 4, j1 = c1 % 4;
                int i2 = c2 / 4, j2 = c2 % 4;
                int i3 = c3 / 4, j3 = c3 % 4;

                for (auto &con1 : configs[0]) {
                    for (auto &con2 : configs[1]) {
                        for (auto &con3 : configs[2]) {
                            // check if valid configuration
                            if (i1 + int(con1.size()) - 1 <= 3 and
                                i2 + int(con2.size()) - 1 <= 3 and
                                i3 + int(con3.size()) - 1 <= 3 and
                                j1 + int(con1[0].size()) - 1 <= 3 and
                                j2 + int(con2[0].size()) - 1 <= 3 and
                                j3 + int(con3[0].size()) - 1 <= 3) {
                                vector<string> answer(4, string(4, '.'));
                                bool skip = false;

                                // put 1st piece
                                for (int i = i1; i < i1 + int(con1.size()); ++i) {
                                    for (int j = j1; j < j1 + int(con1[0].size()); ++j) {
                                        if (answer[i][j] == '.') {
                                            answer[i][j] = con1[i - i1][j - j1];
                                        } else {
                                            if (con1[i - i1][j - j1] == '#') {
                                                skip = true;
                                                break;
                                            }
                                        }
                                    }
                                    if (skip) {
                                        break;
                                    }
                                }
                                if (skip) continue;

                                // put 2nd piece
                                for (int i = i2; i < i2 + int(con2.size()); ++i) {
                                    for (int j = j2; j < j2 + int(con2[0].size()); ++j) {
                                        if (answer[i][j] == '.') {
                                            answer[i][j] = con2[i - i2][j - j2];
                                        } else {
                                            if (con2[i - i2][j - j2] == '#') {
                                                skip = true;
                                                break;
                                            }
                                        }
                                    }
                                    if (skip) {
                                        break;
                                    }
                                }
                                if (skip) continue;

                                // put 3rd piece
                                for (int i = i3; i < i3 + int(con3.size()); ++i) {
                                    for (int j = j3; j < j3 + int(con3[0].size()); ++j) {
                                        if (answer[i][j] == '.') {
                                            answer[i][j] = con3[i - i3][j - j3];
                                        } else {
                                            if (con3[i - i3][j - j3] == '#') {
                                                skip = true;
                                                break;
                                            }
                                        }
                                    }
                                    if (skip) {
                                        break;
                                    }
                                }
                                if (skip) continue;

                                // check all
                                for (int i = 0; i < 4; ++i) {
                                    for (int j = 0; j < 4; ++j) {
                                        if (answer[i][j] != '#') {
                                            skip = true;
                                        }
                                    }
                                }
                                if (skip) continue;

                                return void(cout << "Yes\n");
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "No\n";
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
