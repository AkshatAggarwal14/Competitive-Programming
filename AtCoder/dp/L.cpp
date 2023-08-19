#include <bits/stdc++.h>

using ll = long long;
ll dp[3001][3001];

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> a(N);
    for (auto &x : a) std::cin >> x;

    memset(dp, -1, sizeof(dp));

    std::function<ll(ll, ll)> dfs = [&](ll L, ll R) {
        if (L > R) return 0LL;

        ll &ans = dp[L][R];
        if (ans != -1) return ans;

        if (L == R) return ans = a[L];

        return ans = std::max(a[L] - dfs(L + 1, R), a[R] - dfs(L, R - 1));
    };

    std::cout << dfs(0, N - 1) << '\n';
}