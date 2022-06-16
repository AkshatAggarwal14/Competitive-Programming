#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n, C;
    cin >> n >> C;
    using node = tuple<ll, ll, ll>;
    vector<node> unit(n);
    for (auto &[x, d, h] : unit) cin >> x >> d >> h;
    sort(all(unit), [&](const node &A, const node &B) {
        ll d1 = get<1>(A), h1 = get<2>(A);
        ll d2 = get<1>(B), h2 = get<2>(B);
        return d1 * h1 > h2 * d2;
    });

    vector<ll> mini(n);
    mini[0] = get<0>(unit[0]);
    for (ll i = 1; i < n; ++i) {
        mini[i] = min(mini[i - 1], get<0>(unit[i]));
    }

    ll m;
    cin >> m;
    for (ll i = 0, D, H; i < m; ++i) {
        cin >> D >> H;
        ll L = 0, R = n - 1;
        --L, ++R;
        // find last unit that can satisfy
        ll ans = -1;
        while (R > L + 1) {
            ll M = (R + L) / 2;
            ll d = get<1>(unit[M]);
            ll h = get<2>(unit[M]);
            ll c = mini[M];
            ll mx = (H * D + h * d - 1) / (h * d);
            ll cost = mx * c;
            if (H * D < h * d && cost <= C) {
                L = M;
                ans = cost;
            } else {
                R = M;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
    dbg(mini, unit);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
