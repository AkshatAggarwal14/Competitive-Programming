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

void Solution() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll maxX = 0, minX = 0, maxY = 0, minY = 0;
    ll x = 0, y = 0;
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (s[i] == 'D') y--;
        if (s[i] == 'U') y++;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        if (maxX - minX >= m || maxY - minY >= n) break;
        ans1 = abs(maxY);
        ans2 = abs(minX);
    }
    cout << 1 + ans1 << ' ' << 1 + ans2 << '\n';
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}