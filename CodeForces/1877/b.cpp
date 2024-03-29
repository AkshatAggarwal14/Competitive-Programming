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
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a) cin >> x.second;
    for (auto &x : a) cin >> x.first;
    sort(a.begin(), a.end(), [](const pair<ll, ll> &A, const pair<ll, ll> &B) {
        if (A.first == B.first) return A.second > B.second;
        return A.first < B.first;
    });
    ll ans = p;
    ll csum = 0;
    ll left = n - 1;
    for (ll i = 0; i < n; ++i) {
        csum += a[i].second;
        if (csum >= n - 1) {
            for (ll j = 0; j <= i; ++j) {
                ll here = min(left, a[j].second);
                left -= here;
                ans += min(a[j].first, p) * here;
            }
            break;
        }
    }
    cout << ans << '\n';
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
