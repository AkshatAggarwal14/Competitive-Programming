#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 2e5 + 5;
vector<ll> fib;

void test() {
    ll n, k;
    cin >> n >> k;
    if (k >= ll(fib.size())) return void(cout << "0\n");
    ll cnt = 0;
    for (ll x = 0; fib[k] * x <= n; ++x) {
        ll numerator = n - fib[k] * x;
        ll denominator = fib[k - 1];
        if (numerator % denominator == 0) ++cnt;
    }
    cout << cnt << '\n';
}

int32_t main() {
    fib.push_back(0);
    fib.push_back(1);
    for (ll i = 2;; ++i) {
        if (fib.back() > N) break;
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
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
