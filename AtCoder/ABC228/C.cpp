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
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

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
    ll n, k;
    cin >> n >> k, --k;
    vector<ll> p(n);
    for (ll &x : p) {
        ll a, b, c;
        cin >> a >> b >> c;
        x = a + b + c;
    }
    vector<ll> q = p;
    sort(all(q), greater<>());
    for (ll x : p) cout << (x + 300 >= q[k] ? "Yes\n" : "No\n");
}

void Mine() {
    ll n, k, temp;
    cin >> n >> k, --k;
    vector<ll> p(n);
    o_multiset<ll> points;
    for (ll i = 0; i < n; ++i) {
        ll sum = 0;
        for (ll j = 0; j < 3; ++j) cin >> temp, sum += temp;
        p[i] = sum, points.insert(sum);
    }
    for (ll i = 0; i < n; ++i)
        cout << (n - (ll)points.order_of_key(p[i] + 301LL) <= k ? "Yes\n" : "No\n");
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Mine();
    return 0;
}