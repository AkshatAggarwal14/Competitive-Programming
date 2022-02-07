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
const ll MOD = 1e9 + 7;

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

// https://math.stackexchange.com/questions/582788/distinct-combinations-of-non-distinct-elements
void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for (ll &x : a) cin >> x, ++cnt[x];
    ll p = 1;
    // each obj can be selected.. 0, 1, 2 .. mp[num] times
    for (auto &[x, y] : cnt) p = (p * (y + 1)) % MOD;
    cout << p - 1 << '\n';  // - 1 for None
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