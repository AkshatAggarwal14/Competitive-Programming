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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i], --a[i];
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = sz(a);
    if (n == 1) return void(cout << "0\n");
    vector<ll> ans(k, n - 1);
    --ans[a[0]], --ans[a[n - 1]];
    for (ll i = 1; i < n - 1; ++i) {
        ans[a[i]] -= 2;
        if (a[i - 1] != a[i + 1]) ++ans[a[i]];
    }
    for (ll i = 0; i < k; ++i) cout << ans[i] << ' ';
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