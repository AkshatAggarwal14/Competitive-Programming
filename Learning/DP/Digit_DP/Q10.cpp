// https://practice.geeksforgeeks.org/contest/gfg-mega-contest-qualification-round/problems

#include <bits/stdc++.h>
using namespace std;

// for gcd(sum(dig^4), product) => sum of dig^4 must be divisible by either 2, 3, 5 or 7
array<int, 10> masks = {0b0000, 0b0000, 0b0001, 0b0010, 0b0001, 0b0100, 0b0011, 0b1000, 0b0001, 0b0010};
int64_t dp[18][16][2][3][5][7][2][2][2][3];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int64_t n;
        cin >> n;

        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](const auto &self, int i, int productMask, int mod2, int mod3, int mod5, int mod7, bool tight, bool leading, bool zeroes, int sumGreater)
            -> int64_t {
            if (i == int(s.size())) {
                int64_t value = 0;

                value |= ((mod2 == 0) and ((productMask >> 0) & 1));
                value |= ((mod3 == 0) and ((productMask >> 1) & 1));
                value |= ((mod5 == 0) and ((productMask >> 2) & 1));
                value |= ((mod7 == 0) and ((productMask >> 3) & 1));
                value |= (zeroes and sumGreater == 2);  // contains zeroes and sum is greater than 1
                return value;
            }

            int64_t &ans = dp[i][productMask][mod2][mod3][mod5][mod7][tight][leading][zeroes][sumGreater];
            if (ans != -1) return ans;

            ans = 0;

            int ub = 9;
            if (tight) ub = int(s[i] - '0');
            for (int dig = 0; dig <= ub; ++dig) {
                ans += self(self, i + 1,
                            (productMask | masks[dig]),
                            (mod2 + dig * dig * dig * dig) % 2,
                            (mod3 + dig * dig * dig * dig) % 3,
                            (mod5 + dig * dig * dig * dig) % 5,
                            (mod7 + dig * dig * dig * dig) % 7,
                            tight && (ub == dig),
                            leading && (dig == 0),
                            zeroes or (dig == 0 and !leading),
                            min(2, sumGreater + dig * dig * dig * dig));
            }

            return ans;
        };

        cout << dfs(dfs, 0, 0, 0, 0, 0, 0, true, true, 0, 0) << '\n';
    }
}
