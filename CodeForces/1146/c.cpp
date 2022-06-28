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
    // take 1 element and find farthest element from it by keep dividing other elements in 2 parts, then we get farthest element, and then get farthest from that by querying that and remaining set
    ll n;
    cin >> n;
    auto ask = [&](ll e, ll l, ll r) {
        cout << "1 " << r - l + 1 - (l <= e && e <= r) << ' ' << e << ' ';
        for (ll i = l; i <= r; ++i)
            if (i != e) cout << i << ' ';
        cout << endl;
        ll res;
        cin >> res;
        return res;
    };
    ll D = ask(1, 2, n);
    ll l = 2, r = n;
    while (r > l) {
        ll m = (r + l) / 2;
        ll d = ask(1, l, m);
        if (d != D) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    ll ans = ask(l, 1, n);
    cout << "-1 " << ans << endl;
}

// if bit is set, put in one set otherwise in other
void less_queries() {
    ll n;
    cin >> n;
    ll ans = 0;
    auto ask = [](const vector<ll> &A, const vector<ll> &B) {
        cout << sz(A) << ' ' << sz(B) << ' ';
        for (auto &x : A) cout << x << ' ';
        for (auto &x : B) cout << x << ' ';
        cout << endl;
        ll res;
        cin >> res;
        return res;
    };
    for (ll bit = 0; (1 << bit) < n; ++bit) {
        vector<ll> a, b;
        for (ll i = 1; i <= n; ++i) {
            if (i & (1 << bit))
                a.push_back(i);
            else
                b.push_back(i);
        }
        ans = max(ans, ask(a, b));
    }
    cout << "-1 " << ans << endl;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        // test();
        less_queries();
    }
    return 0;
}