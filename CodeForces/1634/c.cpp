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

// Al + ... + Ar = (r - l + 1) * (A_l + A_r) / 2
// al + ar will be 2a + ... something
// and 2 will cancel out as even common difference
void Solution() {
    ll n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
        vector<vector<ll>> ans(n, vector<ll>(k));
        for (ll j = 0, cnt = 1; j < k; ++j)
            for (ll i = 0; i < n; ++i)
                ans[i][j] = cnt++;
        cout << "YES\n";
        for (ll i = 0; i < n; ++i)
            for (ll j = 0; j < k; ++j) cout << ans[i][j] << " \n"[j == k - 1];
        return;
    }
    if (k == 1) {
        cout << "YES\n";
        for (ll i = 1; i <= n; ++i) cout << i << '\n';
        return;
    }
    cout << "NO\n";
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