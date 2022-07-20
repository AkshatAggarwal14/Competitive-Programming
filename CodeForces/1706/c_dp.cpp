#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5 + 2;
const ll INF = 1e18;

ll dp[N][2];
int a[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i], dp[i][0] = dp[i][1] = -1;
        function<ll(int, int)> dfs = [&](int idx, int turn) {
            if (idx >= n - 1) return 0LL;
            ll &ans = dp[idx][turn];
            if (ans != -1) return ans;
            ll cur = max(max(a[idx + 1], a[idx - 1]) + 1 - a[idx], 0);
            if (turn)
                ans = min(cur + dfs(idx + 2, 1), dfs(idx + 1, 0));  // 101, 1001
            else
                ans = cur + dfs(idx + 2, 0);  // 010
            return ans;
        };
        if (n & 1)
            cout << dfs(1, 0) << '\n';
        else
            cout << dfs(1, 1) << '\n';
    }
}