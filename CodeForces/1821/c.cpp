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
    string s;
    cin >> s;
    int n = int(s.size());

    int ans = n;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        int tans = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == ch) {
                if (cnt) tans = max(tans, int(__lg(cnt) + 1));
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        if (cnt) tans = max(tans, int(__lg(cnt) + 1));
        ans = min(ans, tans);
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
