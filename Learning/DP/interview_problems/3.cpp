// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008caea6/0000000000b76f44#problem

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> int { return int(container.size()); };
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int _testcases = 1;
    cin >> _testcases;
    for (int _tt = 1; _tt <= _testcases; ++_tt) {
        cout << "Case #" << _tt << ": ";

        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll &A : a) cin >> A;
        ll m;
        cin >> m;
        vector<ll> b(m);
        for (ll &B : b) cin >> B;
        map<ll, set<ll>> pos;

        vector<vector<ll>> dp(n, vector<ll>(m + 1, INF));
        // dp[i][j] = time taken to reach index i in text, with position j on keyboard on the last step
        // now we know what character to type next, and we go left or right

        for (ll j = 0; j < m; ++j) {
            if (b[j] == a[0]) dp[0][j] = 0;
            pos[b[j]].insert(j);
        }
        for (ll i = 1; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    ll prev = a[i - 1];
                    auto it = pos[prev].lower_bound(j);
                    if (it != pos[prev].end()) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][*it] + abs(j - *it));
                    }
                    if (it != pos[prev].begin()) {
                        it--;
                        dp[i][j] = min(dp[i][j], dp[i - 1][*it] + abs(j - *it));
                    }
                }
            }
        }
        ll ans = INF;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans << '\n';
    }

    return 0;
}
