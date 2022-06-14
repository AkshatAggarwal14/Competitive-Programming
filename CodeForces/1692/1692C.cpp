#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    vector<vector<char>> grid(8, vector<char>(8));
    for (auto &x : grid)
        for (auto &y : x) cin >> y;
    for (ll i = 1; i < 7; ++i)
        for (ll j = 1; j < 7; ++j)
            if (grid[i][j] == '#')
                if (grid[i - 1][j - 1] == '#' && grid[i + 1][j + 1] == '#' &&
                    grid[i - 1][j + 1] == '#' && grid[i - 1][j + 1] == '#')
                    return void(cout << i + 1 << ' ' << j + 1 << '\n');
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
