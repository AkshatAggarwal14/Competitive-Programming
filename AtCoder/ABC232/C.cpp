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
    ll n, m, u, v;
    cin >> n >> m;
    vector<array<ll, 2>> edges1, edges2, check;
    for (ll i = 0; i < m; ++i) cin >> u >> v, edges1.push_back({min(u, v), max(u, v)});
    for (ll i = 0; i < m; ++i) cin >> u >> v, edges2.push_back({min(u, v), max(u, v)});
    sort(all(edges1)), sort(all(edges2));
    vector<ll> P(n + 1);  // the vector to check all possibilities
    iota(all(P), 0LL);
    dbg(edges1, edges2, P);
    do {
        check.clear();
        for (auto &[x, y] : edges2) check.push_back({min(P[x], P[y]), max(P[x], P[y])});
        sort(all(check));
        if (check == edges1) return void(cout << "Yes\n");
    } while (next_permutation(1 + all(P)));  // permute from 1
    cout << "No\n";
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