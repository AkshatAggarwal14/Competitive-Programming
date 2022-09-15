#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s;
    cin >> s;
    ll n = sz(s);
    ll w, q;
    cin >> w >> q;
    vector<ll> pref(n + 1);
    for (ll i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }
    auto get = [&](ll l, ll r) {
        ll sum = pref[r + 1] - pref[l];
        while (sum > 9) {
            ll t = sum;
            ll t2 = 0;
            while (t) {
                t2 += t % 10;
                t /= 10;
            }
            sum = t2;
        }
        return sum % 9;
    };
    vector<vector<ll>> st(10);
    for (ll i = 0; i + w - 1 < n; ++i)
        st[get(i, i + w - 1)].push_back(i);
    while (q--) {
        pair<ll, ll> L = {INF, INF};
        ll l, r, k;
        cin >> l >> r >> k, --l, --r;
        ll v = get(l, r);
        for (ll i1 = 0; i1 <= 9; ++i1) {
            ll i2 = k - i1 * v;
            i2 = (i2 % 9 + 9) % 9;
            if (i1 == i2) {
                if (sz(st[i1]) < 2) continue;
                if (st[i1][0] + 1 <= L.first) {
                    L.first = st[i1][0] + 1;
                    L.second = st[i1][1] + 1;
                }
            } else {
                if (st[i1].empty() || st[i2].empty()) continue;
                if (st[i1][0] + 1 <= L.first) {
                    L.first = st[i1][0] + 1;
                    L.second = st[i2][0] + 1;
                }
            }
        }
        if (L.first == INF && L.second == INF) L = {-1, -1};
        cout << L.first << ' ' << L.second << '\n';
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
