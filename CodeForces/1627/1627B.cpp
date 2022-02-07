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
    // Handle centre points for odd and even cases
    for (ll i = (n - 1) / 2; i <= n / 2; ++i)
        for (ll j = (m - 1) / 2; j <= m / 2; ++j)
            sx = i, sy = j, bfs.push({i, j}), d[i][j] = 0;
    // bfs from centre points
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
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            ++cnt[d[i][j]];
    ll min_dis = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            amax(min_dis, abs(i - sx) + abs(j - sy));  // distance
    for (auto &[x, y] : cnt)
        while (y--) cout << (x + min_dis) << ' ';
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
        // Better();
        Solution();
    }
    return 0;
}