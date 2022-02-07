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
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    ll p = 1;
    vector<ll> elements(n), suff(n + 1, 0), pref(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        elements[i] = p * v[i];
        p *= -1;
    }
    pref[0] = 0;
    partial_sum(all(elements), 1 + pref.begin());
    suff[n] = 0;
    for (ll i = n - 1; i >= 0; --i) suff[i] = elements[i] + suff[i + 1];
    ll ans = accumulate(all(elements), 0LL);
    for (ll i = n - 2; i >= 0; i -= 2) ans = max({ans, pref[i] - suff[i]});  //!
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