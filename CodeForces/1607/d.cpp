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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    string color;
    multiset<ll> R, B;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    cin >> color;
    for (ll i = 0; i < n; ++i) {
        if (color[i] == 'R') R.insert(a[i]);
        if (color[i] == 'B') B.insert(a[i]);
    }
    for (ll i = 1; i <= n; ++i) {
        if (!B.empty()) {
            if (*B.begin() < i) return void(cout << "NO\n");
            B.erase(B.begin());
        } else {
            if (*R.begin() > i) return void(cout << "NO\n");
            R.erase(R.begin());
        }
    }
    cout << "YES\n";
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}