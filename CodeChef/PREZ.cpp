#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    auto can = [&](ll index) -> pair<bool, string> {
        // calculates moves upto this index
        ll moves = 0;
        string t = s;
        for (ll i = index; i >= 0; --i) {
            t[i] = (char((t[i] - '0' + moves) % 10) + '0');
            moves += (('9' - t[i]) + 1) % 10;
            t[i] = '0';
        }
        return {moves <= k, t};
    };
    ll l = -1, r = n;  // 1 1 1 1 0 0 0
    string ans = s;
    while (r > l + 1) {
        ll m = (l + r) / 2;
        auto check = can(m);
        if (check.first) {
            l = m;
            ans = check.second;
        } else {
            r = m;
        }
    }
    dbg(ans);
    ll pos = 0;
    while (pos < n && ans[pos] == '0') ++pos;
    cout << pos << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}