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
    vector<array<ll, 2>> v(n);
    for (auto &[x, y] : v) cin >> x >> y;
    // sort by length of intervals
    sort(all(v), [&](array<ll, 2> &A, array<ll, 2> &B) { return A[1] - A[0] > B[1] - B[0]; });
    vector<array<ll, 3>> ans;
    for (ll i = 0; i < n; ++i) {
        if (v[i][0] == v[i][1]) {
            ans.push_back({v[i][0], v[i][0], v[i][0]});
            continue;
        }
        ll j1 = i + 1, j2 = i + 1;
        for (; j1 < n; ++j1)
            if (v[j1][0] == v[i][0]) break;
        for (; j2 < n; ++j2)
            if (v[j2][1] == v[i][1]) break;
        assert(!(j1 == n && j2 == n));  // definitely someone exists
        // found same y
        ans.push_back({v[i][0], v[i][1], ((j1 == n) ? (v[j2][0] - 1) : (v[j1][1] + 1))});
    }
    for (auto &[a, b, c] : ans) cout << a << ' ' << b << ' ' << c << '\n';
    cout << '\n';
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