// https://atcoder.jp/contests/abc317/tasks/abc317_f

#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

ll dp[64][2][2][2][2][2][2][10][10][10];

string toBinary(ll n) {
    string s = bitset<64>(n).to_string();
    const auto pos = s.find('1');
    if (pos != string::npos) return s.substr(pos);
    return "0";
}

const ll MOD = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    ll n;
    int a1, a2, a3;
    cin >> n >> a1 >> a2 >> a3;

    string s = toBinary(n);

    // Digit DP in binary!
    auto dfs = [&](const auto &self,
                   int i, bool tight1, bool tight2, bool tight3, bool empty1, bool empty2, bool empty3, int modNum1, int modNum2, int modNum3) -> ll {
        if (i == int(s.size())) {
            return (!empty1 and !empty2 and !empty3 and modNum1 == 0 and modNum2 == 0 and modNum3 == 0);
        }

        int ub1, ub2, ub3;
        ub1 = ub2 = ub3 = 1;
        if (tight1) ub1 = int(s[i] - '0');
        if (tight2) ub2 = int(s[i] - '0');
        if (tight3) ub3 = int(s[i] - '0');

        ll &ans = dp[i][tight1][tight2][tight3][empty1][empty2][empty3][modNum1][modNum2][modNum3];
        if (ans != -1) return ans;
        ans = 0;

        for (int dig1 = 0; dig1 <= ub1; ++dig1) {
            for (int dig2 = 0; dig2 <= ub2; ++dig2) {
                for (int dig3 = 0; dig3 <= ub3; ++dig3) {
                    if ((dig1 ^ dig2 ^ dig3) == 0) {
                        ans += self(self, i + 1,
                                    tight1 && (dig1 == ub1),
                                    tight2 && (dig2 == ub2),
                                    tight3 && (dig3 == ub3),
                                    empty1 && (dig1 == 0),
                                    empty2 && (dig2 == 0),
                                    empty3 && (dig3 == 0),
                                    (modNum1 * 2 + dig1) % a1,
                                    (modNum2 * 2 + dig2) % a2,
                                    (modNum3 * 2 + dig3) % a3);
                        ans %= MOD;
                    }
                }
            }
        }

        return ans;
    };

    cout << dfs(dfs, 0, true, true, true, true, true, true, 0, 0, 0) << '\n';

    return 0;
}
