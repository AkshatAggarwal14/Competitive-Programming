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
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, k;
    cin >> n >> k;
    if (k <= n) return void(cout << k << '\n');
    auto rec = [&](const auto &self, ll Num) -> ll {
        if (Num <= 1) return Num;
        ll ans = 0;
        for (ll b = __builtin_popcountl(Num); b >= 1; --b) {
            ll num = (1LL << b) - 1;
            ll times = Num / num;
            ll left = Num - times * num;
            ll len = times + self(self, left);
            if (len <= n) ans = max(ans, times * b + left);
        }
        return ans;
    };
    cout << rec(rec, k) << '\n';
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
