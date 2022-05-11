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

ll power(ll x, ll y, ll p = MOD) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (ll &x : a) cin >> x, --x;
    for (ll &x : b) cin >> x, --x;
    for (ll &x : c) cin >> x, --x;
    vector<ll> next(n, -1);
    vector<ll> which_cycle(n, -1);
    ll cycle_number = 0;
    for (ll i = 0; i < n; ++i)
        if (a[i] != b[i]) next[a[i]] = b[i];
    for (ll i = 0; i < n; ++i) {
        ll par = a[i];
        if (which_cycle[par] != -1 || next[par] == -1) continue;
        while (which_cycle[par] == -1) {
            which_cycle[par] = cycle_number;
            par = next[par];
        }
        ++cycle_number;
    }
    vector<ll> cnt(cycle_number, 0);
    for (ll i = 0; i < n; ++i)
        if (c[i] != -1 && which_cycle[c[i]] != -1) ++cnt[which_cycle[c[i]]];
    ll res = 0;
    for (ll i = 0; i < cycle_number; ++i)
        if (cnt[i] == 0) ++res;
    cout << power(2, res) << '\n';
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
