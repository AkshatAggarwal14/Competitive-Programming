#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;
using ll = long long;

constexpr int N = 4e4;
constexpr ll MOD = 1e9 + 7;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int> req;
    for (int i = 1; i <= N; ++i) {
        string s = to_string(i);
        if (s == string(s.rbegin(), s.rend())) req.push_back(stoi(s));
    }
    // dp[j] = ways to make sum j
    vector<ll> dp(N + 1);
    dp[0] = 1;
    for (int i = 0; i < 498; ++i)
        for (int j = req[i]; j <= N; ++j)
            (dp[j] += dp[j - req[i]]) %= MOD;

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << dp[k] << '\n';
    }
}