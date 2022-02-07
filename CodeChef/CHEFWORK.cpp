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
    vector<ll> a(n);
    vector<ll> type(n);
    for (ll &x : a) cin >> x;
    for (ll &x : type) cin >> x;
    vector<ll> A[3];
    for (ll i = 0; i < n; ++i) A[type[i] - 1].push_back(a[i]);
    ll ans = LLONG_MAX;
    if (sz(A[0]) && sz(A[1])) amin(ans, *min_element(all(A[0])) + *min_element(all(A[1])));
    if (sz(A[2])) amin(ans, *min_element(all(A[2])));
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