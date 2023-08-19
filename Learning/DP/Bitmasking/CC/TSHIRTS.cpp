// https://www.codechef.com/problems/TSHIRTS?tab=statement

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

ll dp[101][1 << 10];
bool own[10][100];

int main() {
    // If dp[i][mask] = number of ways person p[i]->p[n] get tshirts from available mask => O(10 * 2^100)
    // ! dp[i][mask] = number of ways we can assign tshirt t[i] to available people in the mask, such that all t[1..i] are already assigned => O(100 * 2^10)
    // dp[i][mask] = dp[i + 1][mask] + SUM(dp[i + 1][mask^(1 << j)]) over all valid set bits
    // T_i tshirt to P_j
    // Valid only if P_j owns T_i and P_j doesnt have a tshirt yet

    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(own, 0, sizeof(own));

        int n;
        cin >> n;
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            stringstream in(s);
            int tshirt;
            while (in >> tshirt) {
                own[i][tshirt - 1] = true;
            }
        }

        // if no tshirts available, only one way
        dp[0][0] = 1;

        // i - tshirts, mask - available people
        for (int i = 0; i < 100; ++i) {
            for (int mask = 0; mask < (1 << n); ++mask) {
                dp[i + 1][mask] = dp[i][mask];
                for (int person = 0; person < n; ++person) {
                    if (((mask >> person) & 1) and own[person][i]) {
                        (dp[i + 1][mask] += dp[i][mask ^ (1 << person)]) %= MOD;
                    }
                }
            }
        }

        // number of ways for tshirt 1 to 100 when all people in mask are available
        cout << dp[100][(1 << n) - 1] << '\n';
    }
}