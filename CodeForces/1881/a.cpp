#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    ll ans = 0;
    while (x.size() < s.size() and x.find(s) == string::npos) {
        x += x;
        ++ans;
    }

    string x2 = x + x;
    if (x.find(s) == string::npos and x2.find(s) != string::npos) {
        ans += 1;
    } else if (x.find(s) == string::npos) {
        ans = -1;
    }

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
