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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<array<ll, 2>> LR(m);
    for (ll i = 0, l, r; i < m; ++i) {
        cin >> l >> r;
        --l, --r;
        LR[i] = {l, r};
    }
    ll ans = (*max_element(all(a)) - *min_element(all(a)));
    vector<ll> res{};
    for (ll i = 0; i < n; ++i) {
        // fix as max, reduce others
        vector<ll> diff(n + 1, 0);
        vector<ll> used;
        for (ll j = 0; j < m; ++j) {
            if (i >= LR[j][0] && i <= LR[j][1]) continue;
            ++diff[LR[j][0]];
            --diff[LR[j][1] + 1];
            used.push_back(j + 1);
        }
        for (ll j = 1; j <= n; ++j) diff[j] += diff[j - 1];
        vector<ll> n_a(a);
        for (ll j = 0; j < n; ++j) n_a[j] -= diff[j];
        ll ans_ = *max_element(all(n_a)) - *min_element(all(n_a));
        if (amax(ans, ans_)) {
            res = used;
        }
    }
    cout << ans << '\n';
    cout << sz(res) << '\n';
    for (ll &x : res) cout << x << ' ';
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