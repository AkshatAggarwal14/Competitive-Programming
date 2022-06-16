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
const ll N = 2'00'000 + 5;

void Solution() {
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> diff(N);
    for (ll i = 0, l, r; i < n; ++i) {
        cin >> l >> r;
        ++diff[l];
        --diff[r + 1];
    }
    for (ll i = 1; i <= N; ++i) diff[i] += diff[i - 1];
    vector<ll> pref(N);
    pref[0] = (diff[0] >= k);
    for (ll i = 1; i <= N; ++i) pref[i] = pref[i - 1] + (diff[i] >= k);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}