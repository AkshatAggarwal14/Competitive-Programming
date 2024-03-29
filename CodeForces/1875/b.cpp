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
    ll n, m, k;
    cin >> n >> m >> k;
    multiset<ll> A, B;
    for (ll i = 0, num; i < n; ++i) {
        cin >> num;
        A.insert(num);
    }
    for (ll i = 0, num; i < m; ++i) {
        cin >> num;
        B.insert(num);
    }
    ll ans = 0;

    if (k) {
        ll times = 2 + k % 2;
        for (ll i = 0; i < times; ++i) {
            ll aMin = *A.begin(), aMax = *A.rbegin();
            ll bMin = *B.begin(), bMax = *B.rbegin();
            if (i & 1) {
                if (bMin < aMax) {
                    A.erase(A.find(aMax));
                    B.erase(B.find(bMin));
                    A.insert(bMin);
                    B.insert(aMax);
                }
            } else {
                if (aMin < bMax) {
                    A.erase(A.find(aMin));
                    B.erase(B.find(bMax));
                    A.insert(bMax);
                    B.insert(aMin);
                }
            }
        }
    }

    for (auto &&x : A)
        ans += x;

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
