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
    string s;
    cin >> n >> k >> s;
    if (n == 1) {
        string res = "";
        for (ll i = 0; i < k; ++i) res += s;
        cout << res << '\n';
    } else {
        string res = s;
        ll ctr = 1, ln = sz(s) - 1;
        while (ln >= 0) {
            if (s.substr(ctr, ln) == s.substr(0, ln)) {
                for (ll i = 2; i <= k; ++i) res += s.substr(ln, s.size() - ln);
                cout << res << '\n';
                return;
            } else
                ++ctr, --ln;
        }
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}