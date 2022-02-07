#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void Solution() {
    ll n, q;
    cin >> n >> q;
    map<ll, ll> cnt;
    for (ll i = 0, u, v, d; i < n; ++i) {
        cin >> u >> v >> d;
        cnt[u] += d;
        cnt[v] -= d;
    }
    vector<array<ll, 2>> queries(q);
    for (auto &[u, v] : queries) {
        cin >> u >> v;
        if (!cnt.count(v - 1)) cnt.insert({v - 1, 0});
        if (!cnt.count(u - 1)) cnt.insert({u - 1, 0});
    }
    ll sum = 0;
    for (auto &[x, y] : cnt) {
        sum += y;
        y = sum;
    }
    map<ll, ll> ans;
    sum = 0;
    ll prev = -1;
    ans[-1] = 0;
    for (auto &[x, y] : cnt) {
        if (x == -1) continue;
        ll number = x - prev - 1;
        sum += number * cnt[prev];
        ans[x] = sum + cnt[x];
        sum = ans[x];
        prev = x;
    }

    for (auto &[x, y] : queries) {
        cout << ans[y - 1] - ans[x - 1] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    while (tc--) {
        Solution();
    }
    return 0;
}