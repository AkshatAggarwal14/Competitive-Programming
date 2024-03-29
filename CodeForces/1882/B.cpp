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
    const ll MX = 50;
    int n;
    cin >> n;
    vector<vector<int>> sets(n);
    vector<vector<int>> rem(MX + 1);

    // remove each i and check
    vector<int> count(MX + 1);

    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        sets[i].resize(len);
        for (int j = 0; j < len; ++j) {
            cin >> sets[i][j];
            rem[sets[i][j]].push_back(i);
            ++count[sets[i][j]];
        }
    }

    int ans = 0;
    for (int i = 0; i <= MX; ++i) {
        if (count[i] == 0) continue;
        for (auto &remove : rem[i]) {
            for (auto &j : sets[remove]) {
                --count[j];
            }
        }

        int cnt = 0;
        for (int j = 0; j <= MX; ++j) cnt += (count[j] != 0);
        ans = max(ans, cnt);

        for (auto &remove : rem[i]) {
            for (auto &j : sets[remove]) {
                ++count[j];
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
