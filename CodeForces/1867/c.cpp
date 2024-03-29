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
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> st;
    for (auto &x : a) {
        cin >> x;
        st.insert(x);
    }

    auto query = [&](ll out) {
        cout << out << endl;
        ll in;
        cin >> in;
        return in;
    };

    if (a[0] != 0) {
        query(0);
    } else {
        ll mex = 0;
        while (st.count(mex)) ++mex;

        ll in = query(mex);
        while (in != -1) {
            in = query(in);
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
