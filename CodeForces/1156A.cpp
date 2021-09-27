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
    fo(i, n) cin >> a[i];
    for (ll i = 1; i < n; ++i)
        if ((a[i] == a[i - 1]) || (a[i] == 2 && a[i - 1] == 3) || (a[i] == 3 && a[i - 1] == 2))
            return void(cout << "Infinite");
    ll ans = 0, cnt = 0;
    // square -> circle -> triangle give 1 extra point
    for (ll i = 2; i < n; ++i)
        if (a[i - 2] == 3 && a[i - 1] == 1 && a[i] == 2) cnt++;

    for (ll i = 1; i < n; ++i) {
        if ((a[i] == 1 && a[i - 1] == 2) || (a[i] == 2 && a[i - 1] == 1)) {
            ans += 3;
        } else if ((a[i] == 1 && a[i - 1] == 3) || (a[i] == 3 && a[i - 1] == 1)) {
            ans += 4;
        }
    }
    cout << "Finite\n";
    cout << ans - cnt << '\n';
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