#include <bits/stdc++.h>
using namespace std;

using ll = long long;
/*
For first we only have a way from left, for other teleports we can go to any side and thus take minimum cost teleport to any side.

Use binary search after removing each ith teleporter and try all possibilities.
*/
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        left[i] = i + 1 + a[i];
        right[i] = n - i + a[i];
    }
    vector<pair<ll, ll>> both(n);
    for (int i = 0; i < n; ++i) both[i] = {min(left[i], right[i]), left[i]};
    sort(both.begin(), both.end());
    // Now we have {cost for both sides, cost for first teleport} in sorted order

    vector<ll> pref(n);
    pref[0] = both[0].first;
    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + both[i].first;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (both[i].second > c) continue;
        ll tans = 1;
        ll rem = c - both[i].second;
        ll L = 0, R = n - 1;
        --L, ++R;
        while (R > L + 1) {
            ll M = (L + R) / 2;
            ll sm = 0;
            if (M >= i) {
                sm = pref[M] - both[i].first;
            } else {
                sm = pref[M];
            }
            // sm contains SUM[0, M] excluding the ith teleport cost if there.
            if (sm <= rem) {
                L = M;
            } else {
                R = M;
            }
        }
        if (L >= i) {
            // here already counted the ith person beforehand, thus subtract 1
            tans += (L + 1) - 1;
        } else {
            // not counted, people from [0, L] are L + 1
            tans += L + 1;
        }
        ans = max(ans, tans);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}