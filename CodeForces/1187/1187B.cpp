#ifndef ONLINE_JUDGE
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
    string s, t;
    vector<ll> pos[26];  //vectors to store positions of each letter a-z
    cin >> n >> s;
    for (ll i = 0; i < n; ++i) pos[s[i] - 'a'].push_back(i + 1);
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> t;
        ll cnt[26]{};
        for (auto &c : t) ++cnt[c - 'a'];
        ll ans = -1;
        for (ll j = 0; j < 26; ++j)
            if (cnt[j] > 0) ans = max(ans, pos[j][cnt[j] - 1]);  //pos[j][cnt[j]-1] gives index of jth occurence of jth character in the input string t
        cout << ans << '\n';
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}