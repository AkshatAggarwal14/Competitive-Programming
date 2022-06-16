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

//! 2n - 1 queries
void Solution() {
    ll n;
    cin >> n;
    vector<ll> query(n + 1), ans(n + 1, -1), pos(n + 1, -1);
    // query - used to ask query
    // ans - to output
    // pos[i] - position of i in ans
    auto ask = [&]() -> ll {
        cout << "? ";
        for (ll i = 1; i <= n; ++i) cout << query[i] << ' ';
        cout << endl;
        ll k;
        cin >> k;
        return k;
    };
    // find last element
    /*
        I set last element to n, and then set others to 1
        1 1 1 1 1 n, so this will return some index IF last element is 1.
        2 2 2 2 2 n, so this will return some index IF last element is 2... thus we find last element

        IF NO QUERY GIVES ANSWER, LAST ELEMENT IS n
    */
    for (ll i = 1; i < n; ++i) {
        fill(all(query), i);
        query[n] = n;
        ll id = ask();
        if (id == 0) continue;
        ans[n] = i, ans[id] = n;
        pos[i] = n, pos[n] = id;
        break;
    }
    if (ans[n] == -1) ans[n] = pos[n] = n;
    // use last element to find others
    /*
        last last last last last 1, gives index of 1.
        last last last last last 2, gives index of 2...
    */
    for (ll i = 1; i <= n; ++i) {
        if (pos[i] != -1) continue;
        fill(all(query), ans[n]);
        query[n] = i;
        ll id = ask();
        ans[id] = i, pos[i] = id;
    }
    cout << "! ";
    for (ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;
}

/*
    ! can be done in n queries.
    2 2 2 2 1
    p[id] + 2 = p[n] + 1 -> p[id] = p[n] - 1
    3 3 3 3 1 -> p[id] = p[n] - 2
    k k k k 1 -> p[id] = p[n] - (k - 1), here if id was 0, i.e. we know this value doesnt exist, then p[n] = k - 1, now use this to find all previous queries.
*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}