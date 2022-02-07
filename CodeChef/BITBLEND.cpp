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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll odd_at_odd_index = -1, odd_at_even_index = -1;
    for (ll i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] % 2 == 1) odd_at_even_index = i;
        } else {
            if (a[i] % 2 == 1) odd_at_odd_index = i;
        }
    }
    // no odd
    if (odd_at_even_index == -1 && odd_at_odd_index == -1) return void(cout << "-1\n");
    vector<pair<ll, ll>> eoe, oeo;
    if (odd_at_even_index == -1) {
        // odd at odd index, eoe
        // make evens at even index and odds at odd index
        for (ll i = 0; i < n; ++i) {
            if (i == odd_at_odd_index) continue;
            if (a[i] % 2 != i % 2) {
                eoe.emplace_back(i, odd_at_odd_index);
            }
        }
        cout << sz(eoe) << '\n';
        for (auto &[x, y] : eoe) cout << x + 1 << ' ' << y + 1 << '\n';
    } else if (odd_at_odd_index == -1) {
        // odd at even index, oeo
        // make evens at odd index and odds at even index
        for (ll i = 0; i < n; ++i) {
            if (i == odd_at_even_index) continue;
            if (a[i] % 2 != (i + 1) % 2) {
                oeo.emplace_back(i, odd_at_even_index);
            }
        }
        cout << sz(oeo) << '\n';
        for (auto &[x, y] : oeo) cout << x + 1 << ' ' << y + 1 << '\n';
    } else {
        // odd at odd index, eoe
        // make evens at even index and odds at odd index
        for (ll i = 0; i < n; ++i) {
            if (i == odd_at_odd_index) continue;
            if (a[i] % 2 != i % 2) {
                eoe.emplace_back(i, odd_at_odd_index);
            }
        }
        // odd at even index, oeo
        // make evens at odd index and odds at even index
        for (ll i = 0; i < n; ++i) {
            if (i == odd_at_even_index) continue;
            if (a[i] % 2 != (i + 1) % 2) {
                oeo.emplace_back(i, odd_at_even_index);
            }
        }
        if (sz(oeo) < sz(eoe)) swap(oeo, eoe);
        cout << sz(eoe) << '\n';
        for (auto &[x, y] : eoe) cout << x + 1 << ' ' << y + 1 << '\n';
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