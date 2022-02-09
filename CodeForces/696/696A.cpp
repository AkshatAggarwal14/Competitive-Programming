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
    // look at structure of tree and then observe that they always meet at some common node and that is in shortest path.
    ll q, type, u, v, w;
    cin >> q;
    map<pair<ll, ll>, ll> mp;  // {{u, v}, cost}
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> v >> w;
            if (u > v) swap(u, v);  // v always larger
            while (u != v) {
                if (v % 2 == 0) {
                    mp[{v / 2, v}] += w;
                    v = v / 2;
                } else {
                    mp[{(v - 1) / 2, v}] += w;
                    v = (v - 1) / 2;
                }
                if (u > v) swap(u, v);
            }
        } else {
            cin >> u >> v;
            ll cost = 0;
            if (u > v) swap(u, v);  // v always larger
            while (u != v) {
                if (v % 2 == 0) {
                    cost += mp[{v / 2, v}];
                    v = v / 2;
                } else {
                    cost += mp[{(v - 1) / 2, v}];
                    v = (v - 1) / 2;
                }
                if (u > v) swap(u, v);
            }
            cout << cost << '\n';
        }
    }
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