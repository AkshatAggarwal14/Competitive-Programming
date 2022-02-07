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
    ll unequal = 0;
    for (ll i = 0; i < n; ++i) unequal += (s[i] != s[n - 1 - i]);
    unequal /= 2;
    dbg(unequal, k);
    if (k < unequal) return void(cout << "NO\n");
    ll left = k - unequal;
    // even me toggle 2 bits, odd me toggle 1 bit
    if (left) {
        if (n % 2 == 0 && left % 2 != 0) return void(cout << "NO\n");
    }
    cout << "YES\n";
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