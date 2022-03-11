#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void BETTER() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int sum = 0;
            if (grid[i - 1][j - 1] - '0' + grid[i - 1][j] - '0' + grid[i][j - 1] - '0' + grid[i][j] - '0' == 3) return void(cout << "NO\n");  // L shape
        }
    }
    cout << "YES\n";
}

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (auto &r : grid)
        for (auto &c : r) cin >> c;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                if (j > 0 && vis[i][j - 1]) return void(cout << "NO\n");
                if (i > 0 && vis[i - 1][j]) return void(cout << "NO\n");
                if (j < m - 1 && vis[i][j + 1]) return void(cout << "NO\n");
                if (i < n - 1 && vis[i + 1][j]) return void(cout << "NO\n");

                ll row = i, col = j, len = 0, bred = 0;
                while (row < n && grid[row][j] == '1') row++, ++len;
                while (col < m && grid[i][col] == '1') col++, ++bred;
                for (ll p = 0; p < len; ++p) {
                    for (ll q = 0; q < bred; ++q) {
                        if (grid[p + i][q + j] != '1' || vis[p + i][q + j])
                            return void(cout << "NO\n");
                        vis[p + i][q + j] = true;
                    }
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        // Solution();
        BETTER();
    }
    return 0;
}