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
    vector<ll> A(n, 0), B(n, 0);
    vector<vector<ll>> g(n);
    for (ll i = 1; i < n; ++i) {
        ll p, a, b;
        cin >> p >> a >> b;
        g[--p].push_back(i);
        g[i].push_back(p);
        A[i] = a, B[i] = b;  // {p->i}
    }
    vector<ll> apref, bpref;
    vector<ll> ans(n, -1);
    auto dfs = [&](const auto &self, ll node, ll par) -> void {
        apref.push_back(((!apref.empty()) ? apref.back() : 0) + A[node]);
        bpref.push_back(((!bpref.empty()) ? bpref.back() : 0) + B[node]);

        ll L = 1, R = sz(bpref) - 1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            if (bpref[M] > apref.back()) {
                R = M;
            } else {
                L = M;
            }
        }
        ans[node] = L;

        for (auto &child : g[node]) {
            if (child == par) continue;
            self(self, child, node);
        }
        apref.pop_back();
        bpref.pop_back();
    };
    dfs(dfs, 0, -1);

    for (ll i = 1; i < n; ++i) cout << ans[i] << ' ';
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
