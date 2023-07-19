// https://cses.fi/problemset/task/2417

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1'000'000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), cnt(N + 1, 0);

    for (auto &x : a) cin >> x, ++cnt[x];

    // dp[x] = number of pairs with gcd x
    // dp[x] = number of pairs which are multiple of x - number of pairs with gcd 2x ...
    vector<ll> dp(N + 1, 0);
    for (ll i = N; i >= 1; --i) {
        ll cur = cnt[i];
        for (ll j = 2 * i; j <= N; j += i) {
            cur += cnt[j];
            dp[i] -= dp[j];
        }

        // C(cur, 2) to choose 2 elements out of cur elements
        dp[i] += (cur * (cur - 1)) / 2;
    }

    cout << dp[1] << '\n';
}