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

int cnt[N], a[N];

void test() {
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) cin >> a[i], ++cnt[a[i]];
    int ans = 1;
    for (int i = 2; i < N; ++i) {
        int tans = 0;
        for (int j = i; j < N; j += i)
            tans += cnt[j];
        ans = max(ans, tans);
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
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
