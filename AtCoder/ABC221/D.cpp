// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
const ll N = 2e5 + 10;

void Solution() {
    ll n;
    ll a, b;
    vector<pair<ll, ll>> x;
    ll cnt;
    ll ans[N];
    for (ll i = 0; i < N; ++i) ans[i] = 0;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a >> b;
        x.push_back({a, 1});
        x.push_back({a + b, -1});
    }
    sort(x.begin(), x.end());
    cnt = 0;
    for (ll i = 0; i < (ll)x.size() - 1; ++i) {
        cnt += x[i].second;
        ans[cnt] += ((x[i + 1].first) - (x[i].first));
    }
    for (ll i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}