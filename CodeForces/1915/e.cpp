#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll pref = 0;
    set<ll> st;
    st.insert(0);
    for (ll i = 0; i < n; ++i) {
        if (i & 1) {
            pref += a[i];
        } else {
            pref -= a[i];
        }
        if (st.count(pref)) {
            return void(cout << "YES\n");
        } else {
            st.insert(pref);
        }
    }

    cout << "NO\n";
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
