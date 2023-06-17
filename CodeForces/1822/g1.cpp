#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

ll mp[N];

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x, ++mp[x];
    // b^2 * a[i] <= 1e6
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = ll(a.size());
    ll ans = 0;
    for (ll b = 1; b <= 1000; ++b) {
        if (b != 1) {
            for (int i = 0; i < n; ++i) {
                if (b * a[i] < N && b * b * a[i] < N)
                    ans += mp[a[i]] * mp[b * a[i]] * mp[b * b * a[i]];
            }
        } else {
            // nC3
            for (ll i = 0; i < n; ++i) {
                ll x = mp[a[i]];
                ans += (x * (x - 1) * (x - 2));
            }
        }
    }
    for (ll i = 0; i < n; ++i) mp[a[i]] = 0;
    cout << ans << '\n';
}

int32_t main() {
    memset(mp, 0, sizeof(mp));
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}