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
    string s;
    cin >> s;
    ll n = sz(s);
    ll ans = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        ll left = i + 1;
        ll right = n - i;
        if (s[i] == '1') {
            ans = ans + left * right;
            a[i] = -(left * right);
        } else
            a[i] = (left * right);
    }

    ll best = 0, curr = 0;
    for (ll i = 0; i < n; i++) {
        curr = curr + a[i];
        best = max(best, curr);
        if (curr < 0) curr = 0;
    }
    cout << ans + best << '\n';
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
