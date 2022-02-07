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

// const ll MOD = 1e9 + 7;
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

void Solution() {
    // (ai * (ai^bj) - 1) mod p = 0
    // (ai^bj) < p
    //? ai mod p != 0
    // ai *(ai^bj) mod p = 1
    // ai^bj mod p = a-1i mod p
    // ai^bj = a-1i mod p
    // ai^a-1modp = bj

    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    map<ll, ll> cnt;
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x, ++cnt[x];
    ll ans = 0;
    for (ll &x : a) {
        if (x % p == 0) continue;  // -1 mod P = 0. not possible
        ll inv = power(x, p - 2, p);
        ans += cnt[inv ^ x];
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}