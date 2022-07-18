#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &A : a) cin >> A;
        vector<ll> cost1(n, 0), cost2(n, 0);
        for (ll i = 1; i < n - 1; ++i) {
            if (i & 1)
                cost1[i] = max(max(a[i + 1], a[i - 1]) + 1 - a[i], 0);
            else
                cost2[i] = max(max(a[i + 1], a[i - 1]) + 1 - a[i], 0);
        }
        for (int i = 1; i < n; ++i) cost1[i] += cost1[i - 1];
        for (int i = n - 2; i >= 0; --i) cost2[i] += cost2[i + 1];
        if (n == 4) {
            cout << min(cost1[1], cost2[2]) << '\n';  // 01, 10
        } else if (n % 2 == 0) {
            ll ans = min(cost1[n - 1], cost2[0]);  // 1010, 0101
            for (ll i = 2; i < n - 2; i += 2)
                ans = min(ans, cost1[i] + cost2[i + 1]);  // 1001
            cout << ans << '\n';
        } else {
            cout << cost1[n - 1] << '\n';  // 101
        }
    }
}
