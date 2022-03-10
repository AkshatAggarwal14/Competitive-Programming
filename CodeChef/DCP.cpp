#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> Q(n);
    for (ll &q : Q) cin >> q;
    vector<vector<pair<ll, ll>>> eq(n);
    for (ll i = 0, ci0, x; i < m; ++i) {
        cin >> ci0 >> x, --ci0;
        for (ll j = 0, u, v; j < x; ++j) {
            cin >> u >> v, --v;
            eq[ci0].push_back({u, v});
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (auto &[mul, id] : eq[i])
            Q[id] = (Q[id] + (mul * Q[i]) % MOD) % MOD;
        if (!eq[i].empty()) Q[i] = 0;
    }
    for (ll &q : Q) cout << q << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}