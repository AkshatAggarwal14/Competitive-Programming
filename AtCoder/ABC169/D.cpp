#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pr;
    ll t = n;
    for (ll i = 2; i * i <= n; ++i) {
        ll cnt = 0;
        while (t % i == 0) {
            t /= i;
            ++cnt;
        }
        if (cnt) pr.push_back({i, cnt});
    }
    if (t > 1) pr.push_back({t, 1});
    ll ans = 0;
    // break p^e into 1 + 2 + 3...
    for (auto &[p, e] : pr) {
        // ll x = 1;
        // while (x * (x + 1) <= 2 * e) ++x;
        // --x;
        // ans += x;
        double val = (sqrt(1 + 8 * e) - 1) / 2.0;
        ans += ll(val);
    }
    cout << ans << '\n';
}