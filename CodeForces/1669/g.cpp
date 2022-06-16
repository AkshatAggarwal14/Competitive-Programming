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
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    auto simulate = [&](ll I, ll J) {
        for (ll i = I; i < n - 1; ++i) {
            if (grid[i + 1][J] == '*' || grid[i + 1][J] == 'o') break;
            if (grid[i][J] == '*' && grid[i + 1][J] == '.')
                swap(grid[i][J], grid[i + 1][J]);
        }
    };

    for (ll i = n - 2; i >= 0; --i)
        for (ll j = m - 1; j >= 0; --j)
            if (grid[i][j] == '*') simulate(i, j);

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j)
            cout << grid[i][j];
        cout << '\n';
    }
    cout << '\n';
}

int32_t
main() {
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
