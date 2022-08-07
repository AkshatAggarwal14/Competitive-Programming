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
    // always exist
    set<ll> st;
    ll n;
    cin >> n;
    ll L = 0, R = ll(1e7), pos = -1;
    --L, ++R;
    while (R > L + 1) {
        ll m = (L + R) / 2;
        if (m * m <= n) {
            L = m;
        } else {
            R = m;
            pos = R;
        }
    }
    vector<ll> ans(n, -1);
    set<ll> used;
    for (ll i = n - 1; i >= 0; --i) {
        ll left = pos * pos - i;
        while (left >= n && pos >= 0) {
            --pos;
            left = pos * pos - i;
        }
        while (used.count(left) && pos >= 0) {
            --pos;
            left = pos * pos - i;
        }
        ans[i] = left;
        assert(!used.count(left));
        used.insert(left);
    }
    for (ll i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
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
