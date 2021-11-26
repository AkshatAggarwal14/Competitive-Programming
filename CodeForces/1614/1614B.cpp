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
    ll n, ans = 0;
    cin >> n;
    vector<ll> coords(n + 1, 0);
    vector<pair<ll, ll>> cnt(n);
    for (ll i = 1; auto &[x, y] : cnt) cin >> x, y = i++;
    sort(all(cnt), greater<>());
    ll pos = 1;
    for (ll i = 0; i < n; i += 2) {
        ans += 2 * cnt[i].first * pos;
        coords[cnt[i].second] = pos;
        if (i + 1 < n) {
            coords[cnt[i + 1].second] = -pos;
            ans += 2 * cnt[i + 1].first * pos;
        }
        ++pos;
    }
    cout << ans << '\n';
    for (ll &x : coords) cout << x << ' ';
    cout << '\n';
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