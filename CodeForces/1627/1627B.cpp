#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Better() {
    // boy always try to be in middle, girl always in corner
    ll n, m;
    cin >> n >> m;
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {  // boy positions
        for (ll j = 0; j < m; ++j) {
            ans.push_back(max({abs(i) + abs(j), abs(n - i - 1) + abs(m - j - 1), abs(i) + abs(m - j - 1), abs(n - i - 1) + abs(j)}));  // girl on farthest corner
        }
    }
    sort(all(ans));
    for (ll &X : ans) cout << X << ' ';
    cout << '\n';
}

//! ----------------------------------------------------------------------------

ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> d(n, vector<ll>(m, -1));
    ll sx = -1, sy = -1;
    queue<pair<ll, ll>> bfs;
    if (n % 2 == 0) {
        if (m % 2 == 0) {
            sx = n / 2 - 1, sy = m / 2 - 1;
            bfs.push({sx, sy});
            d[sx][sy] = 0;
            bfs.push({sx, sy + 1});
            d[sx][sy + 1] = 0;
            bfs.push({sx + 1, sy});
            d[sx + 1][sy] = 0;
            bfs.push({sx + 1, sy + 1});
            d[sx + 1][sy + 1] = 0;
        } else {
            sx = n / 2 - 1, sy = m / 2;
            bfs.push({sx, sy});
            d[sx][sy] = 0;
            bfs.push({sx + 1, sy});
            d[sx + 1][sy] = 0;
        }
    } else {
        if (m % 2 == 0) {
            sx = n / 2, sy = m / 2 - 1;
            bfs.push({sx, sy});
            d[sx][sy] = 0;
            bfs.push({sx, sy + 1});
            d[sx][sy + 1] = 0;
        } else {
            sx = n / 2, sy = m / 2;
            bfs.push({sx, sy});
            d[sx][sy] = 0;
        }
    }
    while (!bfs.empty()) {
        ll nx = bfs.front().first;
        ll ny = bfs.front().second;
        bfs.pop();
        for (ll k = 0; k < 4; ++k) {
            ll X = nx + dx[k];
            ll Y = ny + dy[k];
            if (X < 0 || X >= n || Y < 0 || Y >= m) continue;
            if (d[X][Y] != -1) continue;
            d[X][Y] = d[nx][ny] + 1;
            bfs.push({X, Y});
        }
    }
    map<ll, ll> cnt;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cnt[d[i][j]]++;
        }
    }
    dbg(cnt);
    ll min_dis = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            ll dist = abs(i - sx) + abs(j - sy);
            amax(min_dis, dist);
        }
    }
    vector<ll> ans;
    for (auto &[x, y] : cnt) {
        while (y--) ans.push_back(x + min_dis);
    }
    for (ll &gg : ans) cout << gg << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Better();
        // Solution();
    }
    return 0;
}