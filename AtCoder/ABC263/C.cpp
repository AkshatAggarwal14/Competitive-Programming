#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
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
    vector<ll> a;
    auto dfs = [&](const auto &self, ll index) -> void {
        dbg(a);
        if (index == n) {
            for (auto &x : a) cout << x << ' ';
            cout << '\n';
        }
        if (index == 0) {
            for (ll i = 1; i <= m; ++i) {
                a.push_back(i);
                self(self, index + 1);
                a.pop_back();
            }
        } else {
            for (ll i = a[index - 1] + 1; i <= m; ++i) {
                a.push_back(i);
                self(self, index + 1);
                a.pop_back();
            }
        }
    };
    dfs(dfs, 0);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
