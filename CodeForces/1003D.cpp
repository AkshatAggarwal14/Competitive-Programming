#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

void Solution() {
    ll n, q, num;
    cin >> n >> q;
    vector<ll> cnt(32, 0);
    fo(i, n) {
        cin >> num;
        ++cnt[__lg(num)];
    }
    auto calc = [=](ll n) {
        ll ans = 0;
        for (ll i = 32; i >= 0; i--) {
            if (((1LL << i) > n) || (!cnt[i])) continue;

            ll t = __lg(n);
            ll dec = min(cnt[i], n / (1LL << i));
            n -= (1LL << i) * dec;
            ans += dec;
        }
        if (!n) return ans;
        return -1LL;
    };
    while (q--) {
        cin >> num;
        cout << calc(num) << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}