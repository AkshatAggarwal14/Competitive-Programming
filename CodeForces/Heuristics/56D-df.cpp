#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif
using ll = int64_t;
ll n, m;
vector<vector<ll>> a;
vector<vector<bool>> vis;

bool valid(ll x, ll y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (vis[x][y]) return false;
    if (a[x][y] == 1) return false;  // vaccinated
    return true;
}

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

void dfs(ll x, ll y) {
    vis[x][y] = true;
    for (ll i = 0; i < 4; i++) {
        ll X = x + dx[i];
        ll Y = y + dy[i];
        if (valid(X, Y)) {
            if (!vis[X][Y]) {
                dfs(X, Y);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n, vector<ll>(m, 0));
    vis.resize(n, vector<bool>(m, false));
    // 2 - people infected
    // 0 - susceptible
    // 1 - vaccinated
    ll A;
    cin >> A;
    for (ll i = 0; i < A; ++i) {
        ll X, Y;
        cin >> X >> Y;
        a[Y][X] = 2;
    }
    ll V;
    cin >> V;
    for (ll i = 0; i < V; ++i) {
        ll X, Y;
        cin >> X >> Y;
        a[Y][X] = 1;
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                vis[i][j] = 1;
                dfs(i, j);
            }
        }
    }

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (a[i][j] == 0 && vis[i][j] == false) cnt++;
        }
    }
    cout << cnt << '\n';
    // dbg(a);
    return 0;
}