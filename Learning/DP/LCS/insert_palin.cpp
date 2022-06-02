/*
    ! Find Minimum number of insertions to make it a palindrome
    i/p: "acbcbda"
    o/p: len("acdbcbdca") - len(i/p)
    ?  : len(SPS(s)) - len(s)
    Insert some characters to make string palindrome

    ? Make shortest Palindromic Supersequence (SPS)
    -> Find SCS with reverse of string


    ! Minimum number of deletions to make palindrome
    ? len(s) - len(LPS(s))

    * # Insertions = # Deletions as we need to add more elements to pair the unpaired elements.
*/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll N = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    string s, t;
    cin >> s;
    t = s;
    reverse(all(t));
    ll n = ll(s.size());
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    string SPS = "";
    ll x = n, y = n;
    while (x > 0 && y > 0) {
        if (s[x - 1] == t[y - 1]) {  // if equal characters, we move diagonally left, and add char
            SPS += s[x - 1];
            --x, --y;
        } else {
            if (dp[x - 1][y] > dp[x][y - 1]) {  // else we move towards larger value in dp table, and write both
                SPS += s[x - 1];                // add character before moving in the larger direction
                --x;
            } else {
                SPS += t[y - 1];
                --y;
            }
        }
    }
    // now we might have stopped somewhere else instead of the top left corner
    // so we need to add remaining characters
    while (x > 0) SPS += s[x - 1], --x;
    while (y > 0) SPS += t[y - 1], --y;
    reverse(all(SPS));
    cout << SPS << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
