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
    ll root = -1;
    vector<vector<ll>> g(n);
    vector<bool> is_leaf(n, false);
    for (ll i = 0, num; i < n; ++i) {
        cin >> num, --num;
        if (num == i)
            root = i;
        else
            g[num].push_back(i);
    }
    for (ll i = 0; i < n; ++i)
        if (i != root && g[i].empty()) is_leaf[i] = true;
    vector<vector<ll>> segs;
    segs.emplace_back();
    auto dfs = [&](const auto &self, ll node) -> void {
        segs.back().push_back(node);
        for (auto &child : g[node]) {
            self(self, child);
        }
        if (is_leaf[node]) segs.emplace_back();  // go to a new vector every time you hit a leaf
    };
    dfs(dfs, root);
    if (segs.back().empty()) segs.pop_back();
    cout << sz(segs) << '\n';
    for (auto &seg : segs) {
        cout << sz(seg) << '\n';
        for (auto &x : seg) cout << x + 1 << ' ';
        cout << '\n';
    }
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
