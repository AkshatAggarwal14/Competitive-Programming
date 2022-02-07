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
    ll n, k, num;
    cin >> n;
    vector<ll> T(n), vis(n, 0);
    vector<vector<ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> T[i] >> k;
        for (ll j = 0; j < k; ++j) cin >> num, a[i].push_back(num - 1);
    }
    ll ans = 0;
    function<void(ll)> dfs = [&](ll parent) -> void {
        if (vis[parent]) return;
        vis[parent] = 1;
        ans += T[parent];
        for (auto child : a[parent]) {
            if (vis[child]) continue;
            dfs(child);
        }
    };
    dfs(n - 1);
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}