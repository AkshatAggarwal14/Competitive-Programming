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

/*
    negative product?
    sub-array arr[i…j] has a negative product only if pre[i] * pre[j] is negative
*/

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll positive = 1, negative = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] > 0)
            a[i] = 1;
        else
            a[i] = -1;
        if (i > 0)
            a[i] *= a[i - 1];
        if (a[i] == 1)
            positive++;
        else
            negative++;
    }
    cout << positive * negative << ' ' << n * (n + 1) / 2 - positive * negative << '\n';
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
