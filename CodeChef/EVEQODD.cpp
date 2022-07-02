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
    ll n;
    cin >> n;
    vector<ll> a(2 * n);
    for (auto &i : a) cin >> i;
    // first make n odd elements
    ll ops = 0;
    vector<pair<ll, ll>> p;
    for (ll i = 0; i < 2 * n; ++i) {
        ll t = a[i];
        ll cnt = 0;
        while (t % 2 == 0) {
            ++cnt;
            t /= 2;
        }
        p.push_back({cnt, i});
    }
    sort(all(p));
    for (ll i = 0; i < n; ++i) {
        ops += p[i].first;
    }
    for (ll i = n; i < 2 * n; ++i) {
        if (a[p[i].second] % 2) ++ops;
    }
    cout << ops << '\n';
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
