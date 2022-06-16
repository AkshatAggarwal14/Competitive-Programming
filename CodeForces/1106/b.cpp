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
    ll n, m, dish_number, amount, temp;
    cin >> n >> m;
    vector<ll> quantity(n), cost(n);
    set<pair<ll, ll>> dishes;  // {cost, dish_type}
    for (ll i = 0; i < n; ++i) cin >> quantity[i];
    for (ll i = 0; i < n; ++i) cin >> cost[i], dishes.insert({cost[i], i});

    // returns how much removed
    auto remove = [&](const ll &what, const ll &how_much) -> ll {
        if (!dishes.contains({cost[what], what})) return 0;
        ll t = min(how_much, quantity[what]);
        quantity[what] -= t;
        if (quantity[what] == 0) dishes.erase({cost[what], what});
        return t;
    };

    while (m--) {
        cin >> dish_number >> amount;
        ll res = 0;
        temp = remove(dish_number - 1, amount);
        res += temp * cost[dish_number - 1];
        amount -= temp;  // remove present
        while (amount > 0 && !dishes.empty()) {
            ll dish_id = dishes.begin()->second;
            temp = remove(dish_id, amount);
            res += temp * cost[dish_id];
            amount -= temp;
        }
        cout << ((amount == 0) ? res : 0LL) << '\n';
    }
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