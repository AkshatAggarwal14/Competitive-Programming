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
// const ll LG = 32;
const ll LG = 5;

void test() {
    // all values will become 0 in 30 bad keys
    // so need to go atmost 30 values in front
    // first we will use all good keys, later all bad keys
    // because if we take a bad key before good key, the value of good key will be decreased and thus not optimal
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll good_cost = 0, ans = accumulate(all(a), 0LL) - k * n;  // all good
    for (ll i = 0; i < n; i++) {
        ll bad_cost = 0, cnt = 1;
        for (ll j = i; j < min(i + 32, n); j++) {
            bad_cost += (a[j] >> cnt);
            ++cnt;
        }
        ans = max(ans, bad_cost + good_cost);
        good_cost += (a[i] - k);
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
