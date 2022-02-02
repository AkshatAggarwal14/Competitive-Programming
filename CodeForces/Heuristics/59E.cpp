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
    ll n, q;
    cin >> n >> q;
    map<ll, ll> cnt;
    for (ll i = 0, u, v, d; i < n; ++i) {
        cin >> u >> v >> d;
        cnt[u] += d;
        cnt[v] -= d;
    }
    vector<array<ll, 2>> queries(q);
    for (auto &[u, v] : queries) {
        cin >> u >> v;
        if (!cnt.count(v - 1)) cnt.insert({v - 1, 0});
        if (!cnt.count(u - 1)) cnt.insert({u - 1, 0});
    }
    ll sum = 0;
    for (auto &[x, y] : cnt) {
        sum += y;
        y = sum;
    }
    dbg(cnt);
    map<ll, ll> ans;
    sum = 0;
    ll prev = -1;
    ans[-1] = 0;
    for (auto &[x, y] : cnt) {
        if (x == -1) continue;
        ll number = x - prev - 1;
        sum += number * cnt[prev];
        ans[x] = sum + cnt[x];
        sum = ans[x];
        prev = x;
    }

    dbg(ans);
    for (auto &[x, y] : queries) {
        cout << ans[y - 1] - ans[x - 1] << '\n';
    }
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