#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()

ll dx[8] = {0, 0, 1, -1, -1, 1, 1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

void Solution() {
    ll n, m, mx = -1;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> d(n, vector<ll>(m, -1));  // using as visited
    for (auto &v : a)
        for (ll &x : v) cin >> x, mx = max(mx, x);
    auto getX = [&](ll D) { return D / m; };
    auto getY = [&](ll D) { return D % m; };
    auto get = [&](ll x, ll y) { return x * m + y; };
    queue<ll> m_bfs;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            if (a[i][j] == mx)
                m_bfs.emplace(get(i, j)), d[i][j] = 0;

    ll ans = -1;
    while (!m_bfs.empty()) {
        ll x = getX(m_bfs.front());
        ll y = getY(m_bfs.front());
        m_bfs.pop();
        for (ll k = 0; k < 8; ++k) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (d[nx][ny] != -1) continue;
            m_bfs.emplace(get(nx, ny));
            d[nx][ny] = d[x][y] + 1;
            ans = max(ans, d[nx][ny]);
        }
    }

    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}