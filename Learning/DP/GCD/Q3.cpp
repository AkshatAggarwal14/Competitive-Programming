// https://www.codechef.com/problems/COPRIME3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1'000'000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), cnt(N + 1, 0);

    for (auto &x : a) cin >> x, ++cnt[x];

    vector<ll> dp(N + 1, 0);
    // dp[i] = triplets with gcd i
    for (ll i = N; i >= 1; --i) {
        ll cur = cnt[i];
        for (ll j = 2 * i; j <= N; j += i) {
            cur += cnt[j];
            dp[i] -= dp[j];
        }

        // C(cur, 3) triplets which are multiple of i
        dp[i] += (cur * (cur - 1) * (cur - 2)) / 6;
    }

    cout << dp[1] << '\n';
}