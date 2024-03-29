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
    ll n, x;
    cin >> n >> x;

    // 1 2 ...
    ll incLen = n - x;

    // 2 1 ...
    ll decLen = n + x - 2;

    dbg(incLen, decLen);

    set<pair<ll, ll>> st;

    for (ll i = 1; i * i <= incLen; ++i) {
        if (incLen % i == 0) {
            ll m = i;
            ll other = incLen / m;

            if (other % 2 == 0) {
                ll k = (other + 2) / 2;
                if (k >= x) {
                    st.insert(minmax({m, other}));
                }
            }
            if (other != m and m % 2 == 0) {
                ll k = (m + 2) / 2;
                if (k >= x) {
                    st.insert(minmax({m, other}));
                }
            }
        }
    }

    if (incLen != decLen) {
        for (ll i = 1; i * i <= decLen; ++i) {
            if (decLen % i == 0) {
                ll m = i;
                ll other = decLen / m;

                if (other % 2 == 0) {
                    ll k = (other + 2) / 2;
                    if (k >= x) {
                        st.insert(minmax({m, other}));
                    }
                }
                if (other != m and m % 2 == 0) {
                    ll k = (m + 2) / 2;
                    if (k >= x) {
                        st.insert(minmax({m, other}));
                    }
                }
            }
        }
    }

    cout << st.size() << '\n';
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