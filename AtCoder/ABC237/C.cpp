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
    auto check = [&](string S) -> bool {
        for (ll i = 0; i < sz(S); ++i) {
            if (S[i] != S[sz(S) - 1 - i]) return false;
        }
        return true;
    };

    string s;
    cin >> s;
    ll n = sz(s);
    ll l = 0, r = n - 1;
    ll c0 = 0, c1 = 0;
    while (l < n && s[l] == 'a') ++l, ++c0;
    while (r >= 0 && s[r] == 'a') --r, ++c1;
    string left = s.substr(l, r - l + 1);
    dbg(left);
    if (check(left)) {
        if (c0 <= c1)
            cout << "Yes\n";
        else
            cout << "No\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}