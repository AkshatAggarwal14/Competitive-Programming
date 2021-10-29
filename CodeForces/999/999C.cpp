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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ranges::reverse(s);
    map<ll, ll> cnt;
    for (char &c : s) ++cnt[c];
    for (auto &[x, y] : cnt) {
        ll t = min(y, k);
        y -= t, k -= t;
        if (k == 0) break;
    }
    string ans = "";
    for (char &c : s) {
        if (cnt[c] == 0) cnt.erase(c);
        if (cnt.contains(c)) {
            --cnt[c];
            ans += c;
            if (cnt[c] == 0) cnt.erase(c);
        }
    }
    ranges::reverse(ans);
    cout << ans << '\n';
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}