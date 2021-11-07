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

void Solution() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    set<pair<ll, ll>> st;
    for (ll i = 0; i < n; ++i) cin >> x[i] >> y[i];
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            ll xx = x[j] - x[i], yy = y[j] - y[i];
            ll g = gcd(xx, yy);
            if (g == 0) g = 1;
            st.insert({xx / g, yy / g});  // normalise with gcd
        }
    }
    cout << sz(st) << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}