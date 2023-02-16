#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll m;
    cin >> m;
    vector<ll> b(m);
    set<ll> st;
    for (auto &x : b) cin >> x, st.insert(x);
    ll x;
    cin >> x;
    vector<bool> reach(N, false);
    reach[0] = true;
    for (ll i = 0; i < N; ++i) {
        if (reach[i]) {
            for (ll j = 0; j < n; ++j) {
                ll nxt = i + a[j];
                if (nxt >= N) continue;
                if (st.count(nxt)) continue;
                reach[nxt] = true;
            }
        }
    }
    cout << ((reach[x]) ? "Yes\n" : "No\n");
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
