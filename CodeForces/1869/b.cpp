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
    ll n, k, a, b;
    cin >> n >> k >> a >> b, --a, --b;

    vector<pair<ll, ll>> pt(n);
    for (auto &[x, y] : pt) cin >> x >> y;

    auto dist = [&](int i, int j) {
        return abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second);
    };

    ll ans = dist(a, b);
    ll tans1 = INF, tans2 = INF;
    for (int i = 0; i < k; ++i)
        tans1 = min(tans1, dist(a, i));

    for (int i = 0; i < k; ++i)
        tans2 = min(tans2, dist(b, i));

    ans = min(ans, tans1 + tans2);
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
