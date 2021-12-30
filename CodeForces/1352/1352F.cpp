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
    ll n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    if (n1 > 0) {
        if (n1 % 2 == 0) cout << 0;
        for (ll i = 0; i < n2; ++i) cout << 1;
        for (ll i = 0; i < (n1 + 1) / 2; ++i) cout << 10;
        for (ll i = 0; i < n0; ++i) cout << 0;
    } else {
        // n1 = 0 means either one must be 0
        if (n0 == 0)
            for (ll i = 0; i < n2 + 1; ++i) cout << 1;
        else
            for (ll i = 0; i < n0 + 1; ++i) cout << 0;
    }
    cout << '\n';
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