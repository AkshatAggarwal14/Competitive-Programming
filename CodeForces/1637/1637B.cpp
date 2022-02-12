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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    // break into segments of 1, max answer <-
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; ++j) {
            ans += (j - i + 1);
            ans += count(v.begin() + i, v.begin() + j + 1, 0);
        }
    }
    cout << ans << '\n';

    // ll n;
    // cin >> n;
    // vector<ll> a(n);
    // for (ll i = 0; i < n; ++i) cin >> a[i];
    // auto ans = [&](ll L, ll R) -> ll {
    //     vector<vector<ll>> lens;
    //     lens.emplace_back();
    //     lens.back().push_back(a[L]);
    //     for (ll i = L + 1; i <= R; ++i) {
    //         if (a[i] == lens.back().back() + 1 && lens.back()[0] == 0) {
    //             lens.back().push_back(a[i]);
    //         } else {
    //             lens.emplace_back();
    //             lens.back().push_back(a[i]);
    //         }
    //     }
    //     ll res = sz(lens);
    //     for (auto &X : lens)
    //         if (X[0] == 0) res += sz(X);
    //     return res;
    // };
    // ll sum = 0;
    // for (ll i = 0; i < n; ++i)
    //     for (ll j = i; j < n; ++j)
    //         sum += ans(i, j);
    // cout << sum << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}