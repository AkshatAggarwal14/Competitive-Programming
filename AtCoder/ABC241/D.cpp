#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// member functions :
// 1. order_of_key(k) : number of elements strictly lesser than k
// 2. find_by_order(k) : k-th element in the set
template <class key, class value, class cmp = std::less<key>>
using o_map = __gnu_pbds::tree<key, value, cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

void Solution() {
    o_multiset<ll> st;
    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            st.insert(x);
        } else if (type == 2) {
            ll x, k;
            cin >> x >> k, --k;
            ll id = (st.order_of_key(x + 1) - 1) - k;
            if (id < 0)
                cout << "-1\n";
            else
                cout << *st.find_by_order(id) << '\n';
        } else {
            ll x, k;
            cin >> x >> k, --k;
            ll id = st.order_of_key(x) + k;
            if (id >= sz(st))
                cout << "-1\n";
            else
                cout << *st.find_by_order(id) << '\n';
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