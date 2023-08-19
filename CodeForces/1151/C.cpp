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

ll get_segment_number(ll index) {
    ll ans = 0;
    while (index != 0) {
        ans++;
        index /= 2;
    }
    return ans;
}

ll get_odd_count(ll index) {
    ll seg = get_segment_number(index);
    ll cur = 1, cnt = 0, total = 0;
    for (ll i = 1; i < seg; ++i) {
        if (i & 1) cnt += cur;
        total += cur;
        cur *= 2;
    }
    if (seg & 1) {
        ll left = index - total;
        cnt += left;
    }

    return cnt;
}

ll get_ans(ll index) {
    ll odds = get_odd_count(index);
    ll evens = index - odds;

    ll even_sum = (odds % MOD) * (odds % MOD);
    ll odd_sum = (evens % MOD) * ((evens + 1) % MOD);

    return (even_sum % MOD + odd_sum % MOD) % MOD;
}

void test() {
    // [1], [2, 4], [3, 5, 7, 9]
    ll l, r;
    cin >> l >> r;
    cout << ((get_ans(r) - get_ans(l - 1)) % MOD + MOD) % MOD << '\n';
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
