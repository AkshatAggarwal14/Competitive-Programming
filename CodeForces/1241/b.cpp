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
    string s, t;
    cin >> s >> t;
    vector<ll> c1(26, 0), c2(26, 0);
    for (ll i = 0; i < sz(s); ++i) ++c1[s[i] - 'a'];
    for (ll i = 0; i < sz(t); ++i) ++c2[t[i] - 'a'];
    for (ll i = 0; i < 26; ++i)
        if (c1[i] && c2[i]) return void(cout << "YES\n");
    cout << "NO\n";
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
