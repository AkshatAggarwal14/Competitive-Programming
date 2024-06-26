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
    ll m;
    cin >> m;
    vector<string> a(3);
    for (auto &x : a) {
        cin >> x;
        x += x;
        x += x;
    }
    m = a[0].size();

    int ans = INT_MAX;
    sort(a.begin(), a.end());
    do {
        for (char dig = '0'; dig <= '9'; ++dig) {
            int i = 0, pos = 0;
            while (pos < 3 and i < m) {
                if (a[pos][i] == dig) {
                    ++pos;
                    if (pos == 3) {
                        ans = min(ans, i);
                    }
                }
                ++i;
            }
        }
    } while (next_permutation(a.begin(), a.end()));

    if (ans == INT_MAX) ans = -1;
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
