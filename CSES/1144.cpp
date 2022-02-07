// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()

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
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void Solution() {
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n);
    for (ll &x : p) cin >> x;
    o_multiset<ll> st(all(p));
    while (q--) {
        char type;
        ll a, b;
        cin >> type >> a >> b;
        if (type == '?') {
            cout << st.order_of_key(b + 1) - st.order_of_key(a) << '\n';
        } else {
            --a;
            st.erase(st.upper_bound(p[a]));
            p[a] = b;
            st.insert(b);
        }
    }
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}