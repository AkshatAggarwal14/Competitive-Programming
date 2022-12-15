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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    array<ll, 2> cnt;
    cnt[0] = cnt[1] = 0;
    for (auto &x : a) cin >> x, ++cnt[x % 2];
    ll ans = accumulate(all(a), 0LL);
    while (q--) {
        ll type, x;
        cin >> type >> x;
        if (type == 0) {
            // add to evens
            if (x % 2 == 0) {
                ans += cnt[0] * x;
            } else {
                ans += cnt[0] * x;
                cnt[1] = n;
                cnt[0] = 0;
            }
        } else {
            // add to odds
            if (x % 2 == 0) {
                ans += cnt[1] * x;
            } else {
                ans += cnt[1] * x;
                cnt[0] = n;
                cnt[1] = 0;
            }
        }
        cout << ans << '\n';
    }
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
