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
    string s, t;
    ll n, m;
    cin >> n >> m >> s >> t;
    string pref = t.substr(0, n);
    string suff = t.substr(m - n, n);
    if (s == pref and s == suff) {
        cout << 0;
    } else if (s == pref) {
        cout << 1;
    } else if (s == suff) {
        cout << 2;
    } else {
        cout << 3;
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
