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

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (ll i = 0; i < n; ++i) cin >> grid[i];
    if (grid[0][0] == '1') return void(cout << "-1\n");
    vector<array<ll, 4>> ans;
    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = m - 1; j >= 0; --j) {
            if (grid[i][j] == '1') {
                if (j == 0) {
                    ans.push_back({i - 1, j, i, j});
                    grid[i][j] = '0';
                } else {
                    ans.push_back({i, j - 1, i, j});
                    grid[i][j] = '0';
                }
            }
        }
    }
    cout << sz(ans) << '\n';
    for (auto &[a, b, c, d] : ans)
        cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';
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
        Solution();
    }
    return 0;
}