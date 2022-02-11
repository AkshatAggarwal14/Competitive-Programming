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
    // x xk xk^2 xk^3
    // xk^3<=n, thus there will be n/k^3 x's for a given n and k.
    // BS on n, iterate on k

    ll m;
    cin >> m;
    // find maximum n for which ways <= m
    auto ways = [&](ll N) -> ll {
        ll res = 0;
        for (ll k = 2; k * k * k <= N; ++k) res += N / (k * k * k);
        return res;
    };
    ll l = 1, r = ll(1e16);
    --l, ++r;
    while (r > l + 1) {
        ll mid = (r + l) / 2;
        ll x = ways(mid);
        if (x >= m) {  // F F F F T T T T
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << ((ways(r) == m) ? r : -1) << '\n';
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