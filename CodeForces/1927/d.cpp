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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> ans(n);
    ll l = 0, r = 0;
    while (l < n) {
        while (r < n and a[l] == a[r]) {
            ++r;
        }
        if (r == n) {
            while (l < n) {
                ans[l++] = r;
            }
            break;
        } else {
            ans[l] = r;
            ++l;
        }
    }

    dbg(ans);

    ll q;
    cin >> q;
    while (q--) {
        ll L, R;
        cin >> L >> R, --L, --R;
        if (ans[L] > R)
            cout << "-1 -1\n";
        else
            cout << L + 1 << ' ' << ans[L] + 1 << '\n';
    }

    cout << '\n';
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
