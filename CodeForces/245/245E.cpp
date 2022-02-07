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
    string s;
    cin >> s;
    vector<ll> pref(sz(s));
    pref[0] = 1 - 2 * (s[0] == '-');
    for (ll i = 1; i < sz(s); ++i) pref[i] = pref[i - 1] + (1 - 2 * (s[i] == '-'));
    ll mx = *ranges::max_element(pref), mn = *ranges::min_element(pref);
    cout << max({abs(mn), abs(mx), abs(mx - mn)}) << '\n';
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