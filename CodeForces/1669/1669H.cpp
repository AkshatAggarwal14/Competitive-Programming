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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> cnt(31, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        for (ll j = 0; j <= 30; ++j) {
            ll bit = (1LL << j);
            if (!(bit & a[i])) ++cnt[j];
        }
    }
    ll num = 0;
    for (ll i = 30; i >= 0; --i) {
        if (k >= cnt[i]) {
            k -= cnt[i];
            num |= (1LL << i);
        }
    }
    cout << num << '\n';
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
