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
    ll n, x, y, ans = 0;
    cin >> n >> x >> y;
    // create 1 copy in min(x, y) time, so now can use both printers together
    ans += min(x, y);
    --n;
    if (n > 0) {
        // binary search on time for remaining n - 1 copies
        auto can = [&](ll time) -> bool {
            return (time / x + time / y) >= n;
        };

        ll l = 0, r = n * max(x, y), bs = 0;
        while (r > l + 1) {
            ll m = l + (r - l) / 2;
            if (can(m)) {
                r = bs = m;
            } else {
                l = m;
            }
        }
        ans += bs;
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
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}