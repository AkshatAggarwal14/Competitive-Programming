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
    ll n;
    cin >> n;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    vector<ll> ans;
    for (ll I = 0; I < n; ++I)
        for (ll J = 0; J < n; ++J)
            for (ll i = -1; i <= 1; ++i) {
                for (ll j = -1; j <= 1; ++j) {
                    if (!(i == 0 && j == 0)) {
                        ll x = I, y = J;
                        ll s = 0;
                        for (ll _ = 0; _ < n; ++_) {
                            s *= 10;
                            s += (grid[x][y] - '0');
                            x += i, y += j;
                            x %= n, y %= n;
                            x += n, y += n;
                            x %= n, y %= n;
                        }
                        ans.push_back(s);
                    }
                }
            }
    dbg(ans);
    sort(all(ans));
    cout << ans.back() << '\n';
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
