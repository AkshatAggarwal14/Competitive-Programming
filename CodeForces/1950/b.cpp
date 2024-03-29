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
    n *= 2;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if ((i / 2 + j / 2) % 2 == 0) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    cout << "\n";
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
