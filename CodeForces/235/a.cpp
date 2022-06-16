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
    ll n;
    cin >> n;
    auto solve = [&](const auto &self, ll N) {
        if (N <= 2) return N;
        if (N & 1) return (N * (N - 1) * (N - 2));  // if odd then all coprime
        ll P = N * (N - 1);
        ll num = N - 2;
        while (num > 0) {
            if (gcd(P, num) == 1) {  // if even find largest prime with max 2
                P *= num;
                break;
            }
            --num;
        }
        return max(P, self(self, N - 1));  // or solve for smaller odd
    };
    cout << solve(solve, n) << '\n';
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