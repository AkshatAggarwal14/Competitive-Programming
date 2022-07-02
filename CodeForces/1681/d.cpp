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
    ll n, x;
    cin >> n >> x;
    map<ll, ll> ops;
    ops[x] = 0;
    queue<ll> bfs;
    bfs.push(x);
    while (!bfs.empty()) {
        ll par = bfs.front();
        bfs.pop();
        string s = to_string(par);
        if (sz(s) == n) return void(cout << ops[par] << '\n');
        for (auto &c : s) {
            ll dig = c - '0';
            ll npar = dig * par;
            if (!ops.count(npar)) {
                bfs.push(npar);
                ops[npar] = ops[par] + 1;
            }
        }
    }
    cout << "-1\n";
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
