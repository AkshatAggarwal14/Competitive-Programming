#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

const ll N = 1e5;
vector<int> adj[N];
bool vis[N];
ll len = 0;

void dfs(ll x) {
    vis[x] = true;
    len++;
    for (auto node : adj[x]) {
        if (vis[node]) return;  // as only conncected once
        dfs(node);
    }
}

void Solution() {
    vector<ll> lens;
    ll n, num;
    cin >> n;
    for (ll i = 1; i <= n; ++i) cin >> num, adj[i].push_back(num);
    for (ll i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        len = 0;
        dfs(i);
        if (len) lens.push_back(len);
    }
    sort(lens.begin(), lens.end());
    ll sz = lens.size();
    if (sz > 1) {
        ll t = lens[sz - 1] + lens[sz - 2];
        lens.pop_back(), lens.pop_back();
        lens.push_back(t);
        sz--;
    }
    ll ans = 0;
    for (ll i = 0; i < sz; ++i) ans += lens[i] * lens[i];
    cout << ans << '\n';
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