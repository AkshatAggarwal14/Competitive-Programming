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

const ll N = 2'00'000;
void Solution() {
    ll n, w, s, t, p;
    cin >> n >> w;
    vector<ll> supply(N + 2, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> s >> t >> p;
        supply[s] += p;
        supply[t] -= p;  // as excluding t
    }
    for (ll i = 1; i <= N; ++i) supply[i] += supply[i - 1];
    cout << ((*max_element(all(supply)) <= w) ? "Yes\n" : "No\n");
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