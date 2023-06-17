#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &r : grid) cin >> r;
    vector<vector<int>> row(n), col(m);
    vector<string> check(n, string(m, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }
    vector<bool> visr(n, false), visc(m, false);
    for (int i = 0; i < n; ++i) {
        if (!visr[i]) {
            for (int j = 0; j < m; ++j) {
                if (!visc[j]) {
                    vector<int> rs, cs;
                    rs.push_back(i);
                    for (auto &c : row[i]) {
                        cs.push_back(c);
                    }
                    for (auto &c : cs) {
                        for (auto &r : col[c]) {
                            rs.push_back(r);
                        }
                    }
                    for (auto &r : rs) {
                        for (auto &c : row[r]) {
                            cs.push_back(c);
                        }
                    }
                    sort(rs.begin(), rs.end());
                    rs.resize(unique(rs.begin(), rs.end()) - rs.begin());
                    sort(cs.begin(), cs.end());
                    cs.resize(unique(cs.begin(), cs.end()) - cs.begin());
                    for (auto &r : rs) {
                        for (auto &c : cs) {
                            check[r][c] = '#';
                            visr[r] = visc[c] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ((grid == check) ? "YES\n" : "NO\n");
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
