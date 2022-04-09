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
const ll MOD = 32768;  // 998244353

void test() {
    ll n;
    cin >> n;
    for (ll i = 0, u; i < n; ++i) {
        cin >> u;
        // make 0s at last, then shift to make 15 zeroes.
        ll ans = INF;
        for (ll j = 0; j <= 15; ++j) {
            ll pw = (1LL << j);
            ll nxt = ((u / pw) + 1) * pw;
            ll far = nxt - u;
            if (u % pw == 0) far = 0;
            ans = min(ans, far + (15 - j));
        }
        cout << ans << ' ';
    }
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
