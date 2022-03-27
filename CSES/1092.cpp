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
    if ((n * (n + 1) / 2) & 1) return void(cout << "NO\n");
    set<ll> st;
    for (ll i = 1; i <= n; ++i) st.insert(i);
    ll sum = (n * (n + 1)) / 4;
    while (sum > 0 && !st.empty()) {
        if (*st.rbegin() <= sum) {
            sum -= *st.rbegin();
            st.erase(*st.rbegin());
        } else {
            dbg(sum);
            assert(st.count(sum));
            st.erase(sum);
            sum = 0;
        }
    }
    cout << "YES\n";
    cout << sz(st) << '\n';
    for (ll i = 1; i <= n; ++i)
        if (st.count(i)) cout << i << ' ';
    cout << '\n';
    cout << n - sz(st) << '\n';
    for (ll i = 1; i <= n; ++i)
        if (!st.count(i)) cout << i << ' ';
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
