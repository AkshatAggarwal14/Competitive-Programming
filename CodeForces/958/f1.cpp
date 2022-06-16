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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), col(m);
    for (ll &A : a) cin >> A;
    for (ll &c : col) cin >> c;
    vector<ll> what;
    for (ll i = 1; i <= m; ++i)
        while (col[i - 1]--) what.push_back(i);
    ll len = sz(what);
    for (ll i = 0; i <= n - len; ++i) {
        vector<ll> sub(a.begin() + i, a.begin() + i + len);
        sort(all(sub));
        if (sub == what) return void(cout << "YES\n");
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}