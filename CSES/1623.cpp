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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    ll mini = INF;
    for (ll i = 0; i < (1LL << n); ++i) {
        ll sum1 = 0, sum2 = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1LL << j))
                sum1 += arr[j];
            else
                sum2 += arr[j];
        }
        mini = min(mini, abs(sum1 - sum2));
    }
    cout << mini << '\n';
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
