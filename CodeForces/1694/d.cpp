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
    vector<vector<ll>> g(n);
    for (ll i = 1; i <= n - 1; ++i) {
        ll a;
        cin >> a, --a;
        g[a].push_back(i);
    }
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; ++i) cin >> l[i] >> r[i];
    vector<ll> vals(n, 0);
    ll ans = 0;
    function<void(ll)> dfs = [&](ll node) {
        for (auto child : g[node]) {
            dfs(child);
            vals[node] += vals[child];
        }
        if (vals[node] < l[node]) {
            ans++;
            vals[node] = r[node];
        } else if (vals[node] > r[node]) {
            vals[node] = r[node];
        }
    };
    dfs(0);
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
