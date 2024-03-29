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
    vector<int> cnt(26, 0);
    string s;
    cin >> s;
    for (auto &x : s) ++cnt[x - 'a'];
    int mx = 0;
    for (int i = 1; i < 26; ++i) {
        if (cnt[i] > cnt[mx]) {
            mx = i;
        }
    }
    cout << char(mx + 'a') << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
