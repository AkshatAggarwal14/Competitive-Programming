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
    set<ll> vis;
    ll n, k;
    cin >> n >> k;
    queue<ll> bfs;
    auto add = [&](ll E) {
        if (vis.count(E)) return;
        if (E <= n && E >= k) {
            bfs.push(E);
            vis.insert(E);
        }
    };
    add(k);
    while (!bfs.empty()) {
        ll curr = bfs.front();
        bfs.pop();
        string t = to_string(curr);
        reverse(all(t));
        ll op1 = stoll(t);
        ll op2 = curr * 10;
        add(op1);
        add(op2);
    }
    cout << sz(vis) << '\n';
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
