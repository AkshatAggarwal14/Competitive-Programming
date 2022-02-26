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

ll dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void Solution() {
    ll n;
    cin >> n;
    vector<string> grid(n);
    for (auto &X : grid) cin >> X;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll dir = 0; dir < 8; ++dir) {
                ll nx = i + 5 * dx[dir], ny = j + 5 * dy[dir];
                if (nx >= n || ny >= n || nx < 0 || ny < 0) continue;
                ll cnt = 0;
                for (ll k = 0; k <= 5; ++k) {
                    cnt += (grid[i + k * dx[dir]][j + k * dy[dir]] == '#');
                    if (cnt >= 4) return void(cout << "Yes\n");
                }
            }
        }
    }
    cout << "No\n";
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