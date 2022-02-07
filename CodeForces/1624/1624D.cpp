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
    ll n, groups;
    cin >> n >> groups;
    string s;
    cin >> s;
    ll doubles = 0, singles = 0;
    vector<ll> cnt(26, 0);
    for (char &c : s) ++cnt[c - 'a'];
    for (ll i = 0; i < 26; ++i) {
        doubles += cnt[i] / 2;
        singles += cnt[i] % 2;
    }
    ll ans = 0;
    ll t = doubles / groups;
    ans = 2 * t;  // add maximum amount of doubles in each group
    doubles -= t * groups;
    singles += 2 * doubles;        // add leftover doubles to singles
    if (singles >= groups) ans++;  // if we have more singles then we can add 1 letter in each grp
    cout << ans << '\n';
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