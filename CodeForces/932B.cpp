// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

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

ll f(ll n) {
    string s = to_string(n);
    ll p = 1;
    for (ll i = 0; i < s.length(); ++i)
        if (s[i] != '0') p = p * (s[i] - '0');
    return p;
}

ll g(ll n) {
    if (n < 10) return n;
    return g(f(n));
}

const ll N = 1e6;
vector<o_set<ll>> vv(10);
void fill() {
    for (ll i = 1; i <= N; ++i) {
        vv[g(i)].insert(i);
    }
}

void My() {
    ll l, r, k;
    cin >> l >> r >> k;
    cout << vv[k].order_of_key(r + 1) - vv[k].order_of_key(l) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fill();
    ll t;
    cin >> t;
    while (t--)
        My();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}