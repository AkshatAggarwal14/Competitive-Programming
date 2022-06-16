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
    vector<ll> a(n), cnt(n + 3, 0);  //n+3 to handle cases
    for (ll &x : a) cin >> x, ++cnt[x];
    ll ans = 0;
    auto C = [&](const ll &N, const int &R) -> ll {
        if (cnt[N] < R) return 0LL;
        if (R == 1) return cnt[N];                          // C(N, 1)
        if (R == 2) return (cnt[N] * (cnt[N] - 1)) / 2;     // C(N, 2)
        return (cnt[N] * (cnt[N] - 1) * (cnt[N] - 2)) / 6;  // C(N, 3)
    };
    for (ll i = 1; i <= n; ++i) {
        ans += C(i, 2) * C(i + 2, 1);                // i, i, i + 2
        ans += C(i, 1) * C(i + 2, 2);                // i, i + 2, i + 2
        ans += C(i, 1) * C(i + 1, 1) * C(i + 2, 1);  // i, i + 1, i + 2
        ans += C(i, 2) * C(i + 1, 1);                // i, i, i + 1
        ans += C(i, 1) * C(i + 1, 2);                // i, i + 1, i + 1
        ans += C(i, 3);                              // i, i, i
    }
    cout << ans << '\n';
}

void Map() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> cnt;  //! if ai was till 1e9
    for (ll &x : a) cin >> x, ++cnt[x];
    ll ans = 0;
    auto C = [&](const ll &N, const int &R) -> ll {
        if (!cnt.contains(N)) return 0LL;
        if (cnt[N] < R) return 0LL;
        if (R == 1) return cnt[N];                          // C(N, 1)
        if (R == 2) return (cnt[N] * (cnt[N] - 1)) / 2;     // C(N, 2)
        return (cnt[N] * (cnt[N] - 1) * (cnt[N] - 2)) / 6;  // C(N, 3)
    };
    for (auto &[i, y] : cnt) {
        ans += C(i, 2) * C(i + 2, 1);                // i, i, i + 2
        ans += C(i, 1) * C(i + 2, 2);                // i, i + 2, i + 2
        ans += C(i, 1) * C(i + 1, 1) * C(i + 2, 1);  // i, i + 1, i + 2
        ans += C(i, 2) * C(i + 1, 1);                // i, i, i + 1
        ans += C(i, 1) * C(i + 1, 2);                // i, i + 1, i + 1
        ans += C(i, 3);                              // i, i, i
    }
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