#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--) {
        ll h, p, ans = 0, sum = 0;
        cin >> h >> p;
        ll term = 1;
        for (ll i = 1; i <= h; ++i) {
            // Go deeper in tree until we dont have all P tasks
            // At each level, 2 * previous level
            if (term <= p) ans++, sum += term;
            term *= 2;
        }
        ll total = term - 1;
        // Left can be done by all P any time freely
        ll left = total - sum;
        ans += (left + p - 1) / p;
        cout << ans << '\n';
    }
}