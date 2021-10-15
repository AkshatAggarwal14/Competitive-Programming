#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n; i += 2) ans += (a[i + 1] - a[i]);
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}