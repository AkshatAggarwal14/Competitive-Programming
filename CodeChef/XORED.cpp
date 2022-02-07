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

const ll LIM = 5e5;
void Solution() {
    ll n, x;
    cin >> n >> x;
    if (n == 1) return void(cout << x << '\n');
    if (n == 2) return void(cout << "0 " << x << '\n');
    ll xr = 0;
    vector<ll> ans;
    for (ll i = 1; i <= n - 3; ++i) {  // fix n - 3 elements
        ans.push_back(i);
        xr = (xr ^ i);
    }
    //! LMAO hack worked
    ll P, Q, R;
    for (ll PQ_dist = 1;; ++PQ_dist) {
        P = n - 2, Q = P + PQ_dist;  // for making distinct
        R = P ^ Q ^ (x ^ xr);
        while (R == P || R == Q || (R >= 1 && R <= n - 3)) {
            P++, Q++;
            R = P ^ Q ^ (x ^ xr);
        }
        if (P <= LIM && Q <= LIM && R <= LIM) break;  // all valid
    }
    ans.push_back(P), ans.push_back(Q), ans.push_back(R);
    assert(P <= LIM && Q <= LIM && R <= LIM);
    for (auto &X : ans) cout << X << ' ';
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