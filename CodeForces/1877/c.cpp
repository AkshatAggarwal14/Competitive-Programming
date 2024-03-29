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

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void test() {
    ll n, m, k;
    cin >> n >> m >> k;
    // for (ll last = 0; last <= 100; ++last) {
    //     vector<ll> a(n + 2);
    //     a[n + 1] = last;
    //     for (ll i = n; i >= 1; --i) {
    //         a[i] = a[i + 1] % i;
    //     }
    //     set<ll> st;
    //     cout << last << ": ";
    //     for (ll i = 1; i <= n + 1; ++i) {
    //         cout << a[i] << ' ';
    //         st.insert(a[i]);
    //     }

    //     cout << " : " << st.size();
    //     cout << '\n';
    // }
    if (k == 1) {
        cout << "1\n";
    } else if (k == 2) {
        ll validVals = m + 1, group_cnt = validVals / n, left = validVals % n, ans = 0;
        if (group_cnt == 0) {
            if (left >= 1) {
                ans = left - 1;
            }
        } else if (group_cnt == 1) {
            ans = n - 1;
            if (left >= 1) {
                ++ans;
            }
        } else {
            ans = n - 1 + (group_cnt - 1);
            if (left >= 1) {
                ++ans;
            }
        }

        cout << ans << '\n';
    } else if (k == 3) {
        ll validVals = m + 1, group_cnt = validVals / n, left = validVals % n, ans = 0;
        if (group_cnt == 0) {
            ans = 0;
        } else if (group_cnt == 1) {
            if (left >= 1) {
                ans = left - 1;
            }
        } else {
            ans = (n - 1) * (group_cnt - 1);
            if (left >= 1) {
                ans += left - 1;
            }
        }

        cout << ans << '\n';
    } else {
        cout << "0\n";
    }
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
