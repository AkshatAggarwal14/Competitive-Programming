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
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (auto &r : grid)
        for (auto &c : r) cin >> c;
    auto valid = [&](ll I, ll J) -> bool { return (I >= 0 && I < n && J >= 0 && J < m); };
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll sum = grid[i][j];
            for (auto k1 : {1, -1}) {
                for (auto k2 : {1, -1}) {
                    ll k = 1;
                    while (true) {
                        if (!valid(i + k1 * k, j + k2 * k)) break;
                        sum += grid[i + k1 * k][j + k2 * k];
                        ++k;
                    }
                }
            }
            res = max(res, sum);
        }
    }
    cout << res << '\n';
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
