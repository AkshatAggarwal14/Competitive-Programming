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
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> pref(N, 0);
    for (auto &A : a) cin >> A, ++pref[A];
    for (ll i = 0; i < N; ++i) pref[i + 1] += pref[i];
    auto get = [&](int l, int r) {
        if (l == r) return pref[l];
        return pref[r] - pref[l - 1];
    };
    // find number of smaller * larger
    ll res = 0;
    for (ll i = 0; i < n; ++i)
        res += get(1, a[i] - 1) * 1LL * get(a[i] + 1, N);
    cout << res << '\n';
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
