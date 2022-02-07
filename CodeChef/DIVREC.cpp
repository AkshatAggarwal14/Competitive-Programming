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

/*
    a + b + c + d + e = X
    1/a + 1/b + 1/c + 1/d + 1/e = A/B
    n/a + n/b + n/c + n/d + n/e = nA/B = a + b + c + d + e = X
    X = nA/B
    n = XB/A

    now 
    X/n = A/B
    as sum of divisors is > n, A > B
*/

void Solution() {
    ll x, a, b;
    cin >> x >> a >> b;
    if (a == 1 && b == 1 && x == 1) return void(cout << "1\n");
    if (a <= b) return void(cout << "-1\n");
    ll n = b * x;
    if (n % a == 0) {
        cout << n / a << '\n';
    } else {
        cout << "-1\n";
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
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}