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
    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    ll g = a[0];
    fo(i, n - 1) {
        cin >> a[i + 1];
        g = gcd(g, a[i + 1]);
    }
    if (g & 1)
        cout << 0 << '\n';
    else {
        vector<ll> even;
        fo(i, n) if (a[i] % 2 == 0) even.push_back(a[i]);
        ll ans = LLONG_MAX;
        for (ll &x : even) {
            ll cnt = 0;
            while (x % 2 == 0) x /= 2, cnt++;
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
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
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}