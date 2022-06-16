#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;
const ll BITS = 20;
const ll N = 2e5 + 10;
vector<bitset<BITS>> v(N);
vector<vector<ll>> pref(N, vector<ll>(BITS, 0));

void Solution() {
    ll l, r;
    cin >> l >> r;
    ll ans = LLONG_MAX;
    for (ll i = 0; i < BITS; ++i) amin(ans, r - l + 1 - (pref[r][i] - pref[l - 1][i]));
    cout << ans << '\n';
}

int main() {
    for (ll i = 0; i < N; ++i) v[i] = bitset<BITS>(i);
    for (ll i = 1; i < N; ++i) {
        for (ll j = 0; j < BITS; ++j) {
            pref[i][j] += (pref[i - 1][j] + v[i][j]);
        }
    }
    // dbg(pref);
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