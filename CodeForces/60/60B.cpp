#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
template <class T>
using D3 = vector<vector<vector<T>>>;

void Solution() {
    ll k, n, m;
    cin >> k >> n >> m;
    D3<char> adj(k, vector<vector<char>>(n, vector<char>(m)));
    D3<ll> vis(k, vector<vector<ll>>(n, vector<ll>(m, 0)));
    for (ll a = 0; a < k; ++a)
        for (ll b = 0; b < n; ++b)
            for (ll c = 0; c < m; ++c)
                cin >> adj[a][b][c];
    ll x, y;
    cin >> x >> y;  // source
    ll ans = 0;

    array<ll, 6> dx = {1, 0, -1, 0, 0, 0}, dy = {0, 1, 0, -1, 0, 0}, dz = {0, 0, 0, 0, 1, -1};
    auto valid = [&](ll Z, ll X, ll Y) -> bool {
        if (Z < 0 || Z >= k || X < 0 || X >= n || Y < 0 || Y >= m) return false;
        if (vis[Z][X][Y] || adj[Z][X][Y] == '#') return false;
        return true;
    };
    auto dfs = [&](const auto& self, ll Z, ll X, ll Y) -> void {
        if (vis[Z][X][Y]) return;
        vis[Z][X][Y] = 1;
        ans++;
        for (ll i = 0; i < 6; ++i) {
            ll nx = X + dx[i], ny = Y + dy[i], nz = Z + dz[i];
            if (valid(nz, nx, ny)) self(self, nz, nx, ny);
        }
    };

    dfs(dfs, 0LL, x - 1, y - 1);  // for 0 based
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}