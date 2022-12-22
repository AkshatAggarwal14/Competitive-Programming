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
const ll P = 31;  // lowercase characters
const ll MOD = 1e15 + 9;

// number of distinct substrings can be C(1500, 2) > 1e6
// collision in 2 strings = 1 / MOD
// collisions amoung 1e6 substrings = C(1e6, 2) / MOD = 1e12 / MOD
// using 1e15 for MOD -> chance of collision -> 1e-3

void test() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    int n = int(s.size());
    set<ll> st;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        ll hash = 0, power = 1;
        for (int j = i; j < n; ++j) {
            hash += (s[j] - 'a' + 1) * power;
            hash %= MOD;
            power *= P;
            power %= MOD;

            cnt += (t[s[j] - 'a'] == '0');
            if (cnt > k) break;

            st.insert(hash);
        }
    }
    cout << sz(st) << '\n';
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
