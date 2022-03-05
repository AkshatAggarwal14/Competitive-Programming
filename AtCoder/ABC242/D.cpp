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
    string s;
    cin >> s;

    ll q;
    auto ch = [&](char s, ll add) {
        return char('A' + (s - 'A' + add) % 3);
    };
    function<char(ll, ll)> ans = [&](ll level, ll index) {
        if (level == 0) return s[index];
        if (index == 0) return ch(s[0], level);
        // (index % 2 + 1)th child of ans(level - 1, index / 2)
        return ch(ans(level - 1, index / 2), index % 2 + 1);
    };

    cin >> q;
    while (q--) {
        ll t, k;
        cin >> t >> k, --k;
        cout << ans(t, k) << '\n';
    }
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