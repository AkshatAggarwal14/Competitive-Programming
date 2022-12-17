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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '.'));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int cnt = 0;
            for (int k = i - 1; k <= i + 1; ++k)
                for (int l = j - 1; l <= j + 1; ++l)
                    cnt += grid[k][l] == '*';
            if (cnt) {
                if (grid[i][j] == '*' || grid[i][j] == cnt + '0')
                    continue;
                else
                    return void(cout << "NO\n");
            } else if (grid[i][j] != '.')
                return void(cout << "NO\n");
        }
    cout << "YES\n";
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
