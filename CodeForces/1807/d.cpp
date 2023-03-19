#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i - 1];
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll sum = pref[r] - pref[l - 1];
        ll ntot = tot - sum + (r - l + 1) * k;
        if (ntot & 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}