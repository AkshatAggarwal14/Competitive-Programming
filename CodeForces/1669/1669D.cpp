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
    string s;
    cin >> n >> s;
    if ((n == 1 && s != "W") || (s == string(n, 'R')) || (s == string(n, 'B')))
        return void(cout << "NO\n");
    ll cnt = 0, runB = 0, runR = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (cnt != 0)
                if (runB == cnt || runR == cnt) return void(cout << "NO\n");
            cnt = runB = runR = 0;
        } else if (s[i] == 'R') {
            ++cnt, ++runR;
        } else {
            ++cnt, ++runB;
        }
    }
    if (cnt != 0)
        if (runB == cnt || runR == cnt) return void(cout << "NO\n");
    cout << "YES\n";
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
