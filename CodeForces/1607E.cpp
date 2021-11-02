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
    string s;
    cin >> n >> m >> s;
    ll m_c = 1, m_r = 1, x_c = 1, x_r = 1, r = 1, c = 1;
    ll ans1 = 1, ans2 = 1;
    for (ll i = 0; i < sz(s); i++) {
        if (s[i] == 'U') r--;
        if (s[i] == 'D') r++;
        if (s[i] == 'R') c++;
        if (s[i] == 'L') c--;
        m_c = min(m_c, c);
        x_c = max(x_c, c);
        m_r = min(m_r, r);
        x_r = max(x_r, r);
        if (x_c - m_c >= m or x_r - m_r >= n) break;
        ans1 = 1;
        if (m_r < 0) ans1 += abs(m_r);
        if (m_r <= 0) ans1++;
        ans2 = 1;
        if (m_c < 0) ans2 += abs(m_c);
        if (m_c <= 0) ans2++;
    }
    cout << ans1 << ' ' << ans2 << '\n';
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