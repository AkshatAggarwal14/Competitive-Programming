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

void Solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto &row : mat)
        for (auto &cell : row) cin >> cell;
    vector<int> row_min(n, 501), col_min(m, 501);
    for (int i = 0; i < n; ++i) row_min[i] = *min_element(all(mat[i]));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) amin(col_min[j], mat[i][j]);
    }
    vector<pair<char, int>> operations;
    if (n <= m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < row_min[i]; ++j) operations.emplace_back('r', i);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < col_min[i]; ++j) operations.emplace_back('c', i);
    } else {
        // 3x6 matrix filled with 1s, 6 moves by cols, 3 by rows
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < col_min[i]; ++j) operations.emplace_back('c', i);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < row_min[i]; ++j) operations.emplace_back('r', i);
    }
    dbg(row_min, col_min, operations);
    vector<pair<string, int>> ans;
    // if number of cols is less than rows, then use that
    for (auto &[x, y] : operations) {
        if (x == 'r') {
            int mini = 501;
            for (int i = 0; i < m; ++i) amin(mini, mat[y][i]);
            if (mini == 0) continue;
            for (int i = 0; i < m; ++i) --mat[y][i];
            ans.emplace_back("row", y + 1);
        } else {
            int mini = 501;
            for (int i = 0; i < n; ++i) amin(mini, mat[i][y]);
            if (mini == 0) continue;
            for (int i = 0; i < n; ++i) --mat[i][y];
            ans.emplace_back("col", y + 1);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] != 0) return void(cout << "-1\n");
    cout << sz(ans) << '\n';
    for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}