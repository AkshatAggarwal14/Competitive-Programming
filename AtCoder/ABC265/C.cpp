#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

map<char, array<ll, 2>> mp;
void test() {
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    ll x = 0, y = 0;
    while (true) {
        char ch = grid[x][y];
        ll nx = x + mp[ch][0], ny = y + mp[ch][1];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) break;
        if (grid[nx][ny] == '.') return void(cout << "-1\n");
        grid[x][y] = '.';
        x = nx, y = ny;
    }
    cout << x + 1 << ' ' << y + 1 << '\n';
}

int32_t main() {
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
