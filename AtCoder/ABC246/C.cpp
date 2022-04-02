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
    ll n, k, x;
    cin >> n >> k >> x;
    vector<pair<ll, ll>> a(n);
    ll cnt = 0, sum = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        sum += a[i].first;

        a[i].second = a[i].first / x;
        a[i].first = a[i].first % x;
        cnt += a[i].second;
    }
    ll cost = 0;
    if (k > cnt) {
        k -= cnt;
        sort(a.rbegin(), a.rend());
        for (ll i = 0; i < n; ++i, --k) {
            if (k <= 0) {
                cost += a[i].first;
            }
        }
    } else {
        cost = sum - k * x;
    }
    cout << cost << '\n';
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
