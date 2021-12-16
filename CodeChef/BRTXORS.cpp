#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x %= p;
    if (x == 0) return 0;  //! important
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// 1 2 4 7 8 8 8 15 16 16 16..
// Observe pattern after brute force
const ll MOD = 1e9 + 7;
void Solution() {
    ll n;
    cin >> n;
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << 2;
    else if (n == 3)
        cout << 4;
    else {
        ll x = __lg(n);
        ll ans = power(2, x + 1, MOD);
        if ((1LL << x) == n) ans = ((ans - 1) + MOD) % MOD;
        cout << ans;
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
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}