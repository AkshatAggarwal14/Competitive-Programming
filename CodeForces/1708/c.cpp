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
    //? M2 - could also binary search for the first index L such that [L, n] reduces mid value to 0, then for [0, L] print 1 if value smaller, else 0, print 1 for everything in [L, n]
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll tq = 0;
    string ans = "";
    for (int i = n - 1; i >= 0; i--) {
        if (tq < q && a[i] > tq) {
            tq++;  // as here it must have decreased
            ans += '1';
        } else {
            if (a[i] <= tq) {  // already maximum from beginning
                ans += '1';
            } else {
                ans += '0';
            }
        }
    }
    reverse(all(ans));
    cout << ans << '\n';
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
