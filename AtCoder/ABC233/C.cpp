#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void Solution() {
    ll n, x;
    cin >> n >> x;
    vector<vector<ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        ll l;
        cin >> l;
        a[i].resize(l);
        for (ll &A : a[i]) cin >> A;
    }
    ll ways = 0;
    auto dfs = [&](const auto &self, ll bag_number, ll P) {
        if (bag_number == n) {
            if (P == 1) ways++;
            return;
        }
        for (ll i = 0; i < sz(a[bag_number]); ++i)
            if (P % a[bag_number][i] == 0) self(self, bag_number + 1, P / a[bag_number][i]);
    };
    dfs(dfs, 0, x);
    cout << ways << '\n';
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