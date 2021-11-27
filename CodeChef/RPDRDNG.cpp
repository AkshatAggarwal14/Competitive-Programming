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
    vector<ll> b(2 * n);
    for (ll &x : b) cin >> x;
    sort(all(b));
    vector<set<ll>> a(n);
    for (ll i = 0; i < n; ++i) a[i / 2].insert(b[i]);
    for (ll i = 0; i < n; ++i) a[(2 * n - 2 - i) / 2].insert(b[2 * n - 1 - i]);
    for (ll i = 0; i < n; ++i)
        if (sz(a[i]) != 1) return void(cout << "-1\n");  // if more than 1 option
    vector<ll> res(n);
    for (ll i = 0; i < n; ++i) res[i] = *(a[i].begin());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    if (sz(res) != n) return void(cout << "-1\n");  // check unique
    for (ll i = 0; i < n; ++i) cout << res[i] << ' ';
    cout << '\n';
    dbg(a);
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