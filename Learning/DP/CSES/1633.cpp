#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll MOD = 1e9 + 7;

void test() {
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, -1);
    dp[0] = 1;  // 1 way for 0 sum
    auto dfs = [&](const auto &self, ll rem) {
        ll &ans = dp[rem];
        if (ans != -1) return ans;
        ans = 0;
        for (ll i = 1; i <= 6; ++i)
            if (rem - i >= 0)
                (ans += self(self, rem - i)) %= MOD;
        return ans;
    };
    cout << dfs(dfs, n) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
