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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (s[i - 1] == '0');
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') continue;
        // keep farmer at ith position

        // move to get cnt0 in radius of i >= k
        int L = 1, R = n;
        --L, ++R;

        auto can = [&](int far) {
            int cnt0 = pref[min(i + far, n - 1) + 1] - pref[i + 1];
            cnt0 += pref[i] - pref[max(0, i - far)];
            return cnt0;
        };

        while (R > L + 1) {
            int M = (L + R) / 2;
            if (can(M) >= k) {
                R = M;
                ans = min(ans, R);
            } else {
                L = M;
            }
        }
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
