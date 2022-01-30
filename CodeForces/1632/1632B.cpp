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

ll value(vector<ll> a) {
    ll ans = -1;
    for (ll i = 0; i < sz(a) - 1; ++i) {
        amax(ans, (a[i] ^ a[i + 1]));
    }
    return ans;
}

//1 2 4 8

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a;

    ll val = 1;
    while (val * 2 < n) {
        val *= 2;
    }
    dbg(val);

    for (ll i = n - 1; i >= val; --i) a.push_back(i);
    a.push_back(0);
    for (ll i = 1; i < val; ++i) a.push_back(i);

    for (ll &x : a) cout << x << ' ';
    dbg(value(a));
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