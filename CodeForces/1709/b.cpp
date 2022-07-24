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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    vector<ll> pref(n + 1, 0), suff(n + 1, 0);
    for (ll i = 0; i < n - 1; ++i) {
        pref[i + 1] = pref[i] + max(a[i] - a[i + 1], 0LL);
    }
    for (ll i = n - 1; i > 0; --i) {
        suff[i] = suff[i + 1] + max(a[i] - a[i - 1], 0LL);
    }
    while (m--) {
        ll l, r;
        cin >> l >> r, --l, --r;
        if (l > r) {
            cout << suff[r + 1] - suff[l + 1] << '\n';
        } else {
            cout << pref[r] - pref[l] << '\n';
        }
    }
    dbg(pref, suff);
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
