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
    string s, t;
    cin >> s >> t;
    int c0 = 0, c1 = 0;
    while (c0 < sz(s) && s[c0] == 'X') ++c0;
    while (c1 < sz(t) && t[c1] == 'X') ++c1;
    map<char, int> mp;
    mp['S'] = 1;
    mp['M'] = 2;
    mp['L'] = 3;
    auto cmp = [&](int a, int b, char ch = '*') {
        if (ch == 'S') {
            if (a > b) cout << "<\n";
            if (a < b) cout << ">\n";
            if (a == b) cout << "=\n";
        } else {
            if (a > b) cout << ">\n";
            if (a < b) cout << "<\n";
            if (a == b) cout << "=\n";
        }
    };
    if (s[c0] == t[c1])
        cmp(c0, c1, s[c0]);
    else
        cmp(mp[s[c0]], mp[t[c1]]);
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
