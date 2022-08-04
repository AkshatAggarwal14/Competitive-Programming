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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (auto &A : a) cin >> A;
    sort(all(a));
    vector<ll> gap;
    for (ll i = 0; i < m; ++i) {
        ll val = 0;
        if (i > 0) {
            val = a[i] - a[i - 1] - 1;
        } else {
            val = a[i] + n - a[m - 1] - 1;
        }
        if (val > 0) gap.push_back(val);
    }
    sort(gap.rbegin(), gap.rend());
    ll saved = 0;
    ll del = 0;
    for (int i = 0; i < sz(gap); ++i) {
        ll t = gap[i] - del;
        if (t <= 0) break;
        saved++;
        --t;
        del += 2;
        saved += max(0LL, t - 1);
        del += 2;
    }
    cout << n - saved << '\n';
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
