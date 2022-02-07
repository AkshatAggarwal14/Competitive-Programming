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
    // sum = length of subarray
    // pref[r] - pref[l - 1] = r - (l - 1)
    // pref[i] - pref[j] = i - j
    // pref[i] - i = constant
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
        pref[i] += ((i == 0) ? 0 : pref[i - 1]) + (s[i - 1] - '0');
    ll ans = 0;
    map<ll, ll> mp;
    for (ll i = 0; i <= n; ++i) {
        ans += mp[pref[i] - i];
        ++mp[pref[i] - i];
    }
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