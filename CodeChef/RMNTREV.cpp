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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    deque<ll> P;
    for (ll i = 0; i < k; ++i) {
        if (i % 2 == 0)
            P.push_back(i);
        else
            P.push_front(i);
    }
    if (k % 2) reverse(all(P));
    for (ll i = k; i < n; ++i) P.push_back(i);
    string ans(n, '.');
    for (ll i = 0; i < n; ++i) ans[P[i]] = s[i];
    cout << ans << '\n';
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