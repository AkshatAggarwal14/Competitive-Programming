#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll((x).size()))
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

/*
Binary search for Even N, even sum - odd sum for Odd N
http://www.usaco.org/index.php?page=viewproblem&cpid=1169
*/
void Solution() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) cin >> h[i];
    ll l = 0, r = *min_element(all(h));

    auto can = [&](ll target) -> pair<bool, ll> {
        vector<ll> n_h(h);
        ll operations = 0;
        for (ll i = 0; i < n - 1; ++i) {
            if (n_h[i] < target) return {false, -1};
            ll to_reduce = n_h[i] - target;
            n_h[i] -= to_reduce;
            n_h[i + 1] -= to_reduce;
            operations += 2 * to_reduce;
        }
        for (ll i = 0; i < n; ++i)
            if (n_h[i] != target) return {false, -1};
        return {true, operations};
    };

    if (n % 2 == 0) {
        // for even if X is possible, X - 1 is also possible
        // min number of bags used for largest true value
        // T T T T F F F
        // find last true
        --l, ++r;
        ll ans = -1;
        while (r > l + 1) {
            ll m = (r + l) / 2;
            pair<bool, ll> c = can(m);
            if (c.first) {
                ans = c.second;
                l = m;
            } else {
                r = m;
            }
        }
        cout << ans << '\n';
    } else {
        // in odd
        /*
            x1 - A = T
            x2 - A - B = T
            x3 - B - C = T
            x4 - C - D = T
            x5 - D = T

            x1 + x3 + x5 - (x2 + x4) = T
        */
        ll even_sum = 0, odd_sum = 0;
        for (ll i = 0; i < n; ++i) {
            if (i & 1)
                odd_sum += h[i];
            else
                even_sum += h[i];
        }
        ll target = even_sum - odd_sum;
        if (target < l || target > r) return void(cout << "-1\n");
        pair<bool, ll> c = can(target);
        assert(c.first);
        cout << c.second << '\n';
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
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}