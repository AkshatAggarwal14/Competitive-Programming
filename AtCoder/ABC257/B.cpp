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
    ll k, n, q;
    cin >> n >> k >> q;
    vector<ll> pos(k), mark(n);
    for (ll i = 0, num; i < k; ++i) cin >> num, mark[num - 1] = 1, pos[i] = num - 1;
    for (ll i = 0; i < q; ++i) {
        ll id;
        cin >> id, --id;
        if (pos[id] == n - 1 || mark[pos[id] + 1]) continue;
        mark[pos[id] + 1] = 1;
        mark[pos[id]] = 0;
        ++pos[id];
    }
    for (ll i = 0; i < k; ++i) cout << pos[i] + 1 << ' ';
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
