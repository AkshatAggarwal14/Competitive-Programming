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

const ll INF = 1e18;
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    cin >> n;
    vector<ll> dp(N, -1);

    auto dfs = [&](const auto &self, ll num) -> ll {
        ll &ans = dp[num];
        if (ans != -1) return dp[num];
        if (num == 0) return ans = 0;
        ans = INF;
        ll temp = num;
        while (temp) {
            ans = min(ans, 1 + self(self, num - temp % 10));
            temp /= 10;
        }
        return ans;
    };

    cout << dfs(dfs, n) << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
