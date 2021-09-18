#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
using str = string;
template <class T>
using v = vector<T>;
using vl = v<ll>;
using vvl = v<vl>;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int N = 100010;
vector<ll> cnt(N, 0);
vector<ll> dp(N, 0);

void solve() {
    ll n;
    cin >> n;
    fo(i, n) {
        ll num;
        cin >> num;
        cnt[num]++;
    }
    dp[0] = 0;
    for (int i = 1; i < N; i++) dp[i] = i * cnt[i];
    for (int i = 1; i < N; ++i) {
        if (i > 1) dp[i] += dp[i - 2];
        if (dp[i - 1] > dp[i]) dp[i] = dp[i - 1];  //as removing previous would be ok
    }
    cout << dp[N - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}