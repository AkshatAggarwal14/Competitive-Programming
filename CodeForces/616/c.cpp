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
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string &x : grid) cin >> x;
    vector<vector<ll>> which_cc(n, vector<ll>(m, -1));  // visited as well as which_cc
    vector<pair<ll, ll>> curr_cc;
    ll dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    function<void(ll, ll)> dfs = [&](ll x, ll y) {
        which_cc[x][y] = 0;  // mark visited
        curr_cc.push_back({x, y});
        for (ll k = 0; k < 4; ++k) {
            ll nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '*') continue;     //blocked
            if (which_cc[nx][ny] != -1) continue;  //visited
            dfs(nx, ny);
        }
    };
    ll cc_number = 1;
    vector<ll> sizes = {0};
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] == '*') which_cc[i][j] = 0;
            if (which_cc[i][j] == -1 && grid[i][j] == '.') {
                curr_cc.clear();
                dfs(i, j);
                sizes.push_back(sz(curr_cc));
                for (auto &[X, Y] : curr_cc) which_cc[X][Y] = cc_number;
                ++cc_number;
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                ll s = 1;  // for this cell
                set<ll> st;
                for (ll k = 0; k < 4; ++k) {
                    ll nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    st.insert(which_cc[nx][ny]);
                }
                for (auto &T : st) s += sizes[T];
                cout << (s % 10);  //! :weary:
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}