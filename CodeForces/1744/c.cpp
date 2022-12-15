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
    ll n;
    char c;
    string s;
    cin >> n >> c >> s;
    set<ll> st;
    for (ll i = 0; auto &x : s) {
        if (x == 'g') st.insert(i);
        ++i;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == c) {
            auto it = st.lower_bound(i);
            if (it == st.end()) {
                ans = max(ans, n - i + *st.begin());
            } else {
                ans = max(ans, *it - i);
            }
        }
    }
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
