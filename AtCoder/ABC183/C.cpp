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
    cin >> n >> k;
    vector<vector<ll>> T(n, vector<ll>(n));
    for (auto &x : T)
        for (auto &y : x) cin >> y;
    vector<ll> p(n + 1);
    iota(all(p), 0);
    p[n] = 0;
    // 0 1 2 3 ... n-1 0 <- permute all between 0, and then take adjacent to find sum
    ll ways = 0;
    do {
        ll sum = 0;
        for (ll i = 0; i < n; ++i) sum += T[p[i]][p[i + 1]];
        ways += (sum == k);
    } while (next_permutation(p.begin() + 1, p.begin() + n));
    cout << ways << '\n';
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