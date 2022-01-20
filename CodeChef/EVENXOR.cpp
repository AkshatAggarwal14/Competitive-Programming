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

bool check(vector<ll> a) {
    for (ll i = 1; i < sz(a) - 1; ++i) {
        for (ll j = i + 1; j < sz(a); ++j) {
            unsigned int x = (unsigned int)(a[i] ^ a[j]);
            if (__builtin_popcount(x) & 1) return false;
        }
    }
    return true;
}

void Solution() {
    // https://oeis.org/A001969
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    // a(1) = 0; for n > 1: a(n) = 3*n-3 - a(n/2) if n even, a(n) = a((n+1)/2)+n-1 if n odd
    a[1] = 0;
    for (ll i = 2; i <= n; ++i) {
        if (i % 2 == 0)
            a[i] = 3 * i - 3 - a[i / 2];
        else
            a[i] = a[(i + 1) / 2] + i - 1;
    }
    // assert(check(a));
    for (ll i = 1; i <= n; ++i) cout << a[i] << ' ';
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