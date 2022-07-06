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
    vector<ll> a(n);
    for (ll &i : a) cin >> i, --i;
    vector<ll> which_cycle(n, -1);
    vector<vector<ll>> cycles;
    ll cycle_number = 0;
    for (ll i = 0; i < n; ++i) {
        ll par = a[i];
        if (which_cycle[par] != -1) continue;
        vector<ll> curr_cycle;
        while (which_cycle[par] == -1) {
            which_cycle[par] = cycle_number;
            curr_cycle.push_back(par);
            par = a[par];
        }
        cycles.push_back(curr_cycle);
        ++cycle_number;
    }
    ll ans = 0;
    for (auto &cycle : cycles) {
        ll mx = 0;
        sort(all(cycle));
        for (ll i = 1; i < sz(cycle); ++i) {
            mx = gcd(mx, cycle[i] - cycle[i - 1]);
        }
        ans = gcd(ans, mx);
    }
    if (ans == 0) ans = n;
    cout << ans << '\n';
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
