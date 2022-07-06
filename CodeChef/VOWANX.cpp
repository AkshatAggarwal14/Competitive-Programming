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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n + 10);
    for (int i = 1; i < n; ++i) {
        if ("aeiou"s.find(s[i]) != string::npos) {
            // flip all from [1, i]
            pref[i] ^= 1;
            pref[0] ^= 1;
        }
    }
    for (ll i = 1; i <= n; ++i) pref[i] ^= pref[i - 1];
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        if (pref[i]) {
            s1 += s[i];
        } else {
            s2 += s[i];
        }
    }
    reverse(all(s1));
    cout << s1 << s2 << '\n';
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
