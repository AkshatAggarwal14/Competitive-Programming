#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    a.push_back(q + 1);  // for delimiter at end
    ll cnt = 0, ans = 0;
    for (auto &A : a) {
        if (A <= q) {
            ++cnt;
        } else {
            if (cnt >= k) {
                ll lim = cnt - k + 1;
                ll sum = lim * (lim + 1) / 2;
                // [1, 2, .. cnt - k + 1]
                ans += sum;
            }
            cnt = 0;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
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
