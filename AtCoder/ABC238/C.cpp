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
const ll MOD = 998244353;

void Solution() {
    auto SUM = [&](ll N) { return ((N % MOD) * ((N % MOD) + 1) / 2) % MOD; };
    ll n;
    cin >> n;
    ll TEN = stoll("1" + string(sz(to_string(n)) - 1, '0'));
    ll ans = SUM(n - TEN + 1);
    TEN /= 10;
    while (TEN) {
        ll LAST = stoll(string(sz(to_string(TEN)), '9'));
        ans += (SUM(LAST - TEN + 1) % MOD);
        ans %= MOD;
        TEN /= 10;
    }
    cout << ans % MOD << '\n';
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