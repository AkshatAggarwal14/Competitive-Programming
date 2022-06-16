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

// https://stackoverflow.com/questions/31750842/find-minimum-cost-to-convert-array-to-arithmetic-progression
void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    // make AP, observation for 3 elements.
    if (sz(a) <= 2) return void(cout << "0\n");
    ll ans = sz(a);
    for (ll i = 0; i < sz(a) - 1; i++) {
        for (ll j = i + 1; j < sz(a); j++) {
            /* TO NOT DEAL WITH DOUBLE, MULTIPLY EVERYTHING BY J - I */
            ll delta = a[j] - a[i];  // real delta is (a[j] - a[i])/(j - i)
            ll cnt = 0;
            for (ll k = 0; k < sz(a); k++) {
                if (k == i) continue;
                // a[k] + delta * (distance b/w i and k) == a[i] for AP
                if (a[k] * (j - i) + delta * (i - k) != a[i] * (j - i)) cnt++;
            }
            amin(ans, cnt);
        }
    }
    cout << ans << '\n';
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