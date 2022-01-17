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
    vector<array<ll, 2>> a(n);
    for (auto &[u, v] : a) cin >> u >> v, --u, --v;
    const auto check = [&](ll i1, ll i2) -> vector<ll> {
        vector<ll> ans;
        for (ll i = 0; i < n; ++i) {
            ll nxt = -1;
            if (a[i1][0] == i2) nxt = a[i1][1];
            if (a[i1][1] == i2) nxt = a[i1][0];
            if (nxt == -1) return {};
            ans.push_back(nxt + 1);
            i1 = i2;
            i2 = nxt;
        }
        return ans;
    };
    // 2 choices only for first, then only 1 choice
    if (sz(check(0, a[0][0])))
        for (auto &x : check(0, a[0][0])) cout << x << ' ';
    else
        for (auto &x : check(0, a[0][1])) cout << x << ' ';
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
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}