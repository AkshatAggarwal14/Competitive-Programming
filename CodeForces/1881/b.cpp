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
    ll a, b, c;
    cin >> a >> b >> c;
    priority_queue<ll> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    ll mn = min({a, b, c});
    ll ans = 0;
    while (pq.top() != mn) {
        ll mx = pq.top();
        pq.pop();
        pq.push(mn);
        pq.push(mx - mn);
        mn = min({mn, mx - mn});
        ++ans;
        if (ans > 3) return void(cout << "NO\n");
    }

    cout << "YES" << '\n';
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
