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
    for (ll i = 1, p; i < n; ++i) {
        cin >> p;
        g[p - 1].push_back(i);
    }
    string s;
    cin >> s;
    ll ans = 0;
    auto dfs = [&](const auto &self, ll node) -> pair<ll, ll> {
        ll c_B = 0, c_W = 0;
        c_B += (s[node] == 'B');
        c_W += (s[node] == 'W');
        for (auto &child : g[node]) {
            auto C = self(self, child);
            c_B += C.first;
            c_W += C.second;
        }
        if (c_B == c_W) ++ans;
        return {c_B, c_W};
    };
    dfs(dfs, 0);
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
