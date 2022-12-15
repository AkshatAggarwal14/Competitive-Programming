// Find count of numbers with product K in [L, R], K -> 1e4
// https://www.codingninjas.com/codestudio/problems/numbers-with-product-k_1796206

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[10005][10][2][2];

int dfs(string& num, int digs, int product, bool leading, bool tight, int K) {
    if (product > K) return 0;
    if (digs == 0)
        return product == K;

    int& ans = dp[product][digs][leading][tight];
    if (ans != -1) return ans;

    ans = 0;

    int ub = ((tight) ? num[int(num.size()) - digs] - '0' : 9);
    for (int dig = 0; dig <= ub; ++dig) {
        if (dig == 0 && !leading) {
            ans += dfs(num, digs - 1, product, 0, tight && (ub == dig), K);
        } else {
            ans += dfs(num, digs - 1, product * dig, 1, tight && (ub == dig), K);
        }
    }
    return ans;
}

int get_count(int number, int K) {
    memset(dp, -1, sizeof(dp));
    string s = to_string(number);
    return dfs(s, int(s.size()), 1, 0, 1, K);
}

int numsWithProductK(int L, int R, int K) {
    return get_count(R, K) - get_count(L - 1, K);
}

int main() {
    ll L, R, K;
    cin >> L >> R >> K;
    cout << numsWithProductK(L, R, K);
}