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
    int n, k, r, c;
    cin >> n >> k >> r >> c, --r, --c;
    vector<string> grid(n, string(n, '.'));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ((i + j) % k == 0) grid[i][j] = 'X';
    int col = int(grid[r].find('X'));
    auto res = grid;
    int diff = c - col;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            res[((i + diff) % n + n) % n][j] = grid[i][j];
    for (auto &x : res) cout << x << '\n';
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
