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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &A : a) cin >> A;
    sort(all(a));
    vector<ll> pref(n, 0);
    for (ll i = 1; i < n; ++i) {
        pref[i] = pref[i - 1];
        pref[i] += (a[i] - a[i - 1]) * i;
    }
    ll ans = 0, sum = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (sum >= pref[i]) break;
        sum += a[i];
        ++ans;
    }
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
