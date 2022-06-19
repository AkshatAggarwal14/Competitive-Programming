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
    vector<ll> a(n + 1);
    ll xr = 0;
    for (ll &i : a) cin >> i, xr ^= i;
    ll useful = -1;
    dbg(xr);
    sort(all(a));
    for (ll i = 0; i <= n; ++i) {
        if ((a[i] ^ xr) == 0) useful = i;
    }
    if (useful == -1) useful = 0;
    dbg(useful);
    // when n is odd, xor of everything except useful query is 0 as they have even occurences
    vector<ll> ans;
    for (ll i = 0; i <= n; ++i) {
        if (i == useful) continue;
        ans.push_back(a[i] ^ a[useful]);
    }
    for (ll &i : ans) cout << i << ' ';
    cout << '\n';
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
