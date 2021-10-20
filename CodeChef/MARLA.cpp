#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> strength(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> strength[i][j];
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    ll cnt = 0;

    ll dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    auto valid = [&](ll x, ll y, ll color) -> bool {
        if (x < 0 || y < 0 || x >= n || y >= m) return false;
        if (strength[x][y] != color || vis[x][y]) return false;  // visit same color only
        return true;
    };
    auto dfs = [&](const auto &self, ll x, ll y, ll color) -> void {
        if (vis[x][y]) return;
        vis[x][y] = 1;
        cnt++;
        for (ll k = 0; k < 4; ++k) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (valid(nx, ny, color)) self(self, nx, ny, color);
        }
    };

    ll mn_strength = LLONG_MAX, mx_cnt = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cnt = 0;
            dfs(dfs, i, j, strength[i][j]);
            if (cnt > mx_cnt) {  // if more count take this
                mx_cnt = cnt, mn_strength = strength[i][j];
            } else if (cnt == mx_cnt) {  // take equal count, less strength
                mn_strength = min(mn_strength, strength[i][j]);
            }
        }
    }
    cout << mn_strength << ' ' << mx_cnt << '\n';
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