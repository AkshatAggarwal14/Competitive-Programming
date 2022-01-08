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
    set<ll> choices;
    auto gen = [&](const auto &self, string curr, ll num_digs, ll d, ll curr_digit) {
        if (num_digs == 18 || curr_digit < 0 || curr_digit >= 10) return;
        curr += char(curr_digit + '0');
        choices.insert(stoll(curr));
        self(self, curr, num_digs + 1, d, curr_digit + d);
    };
    for (ll i = 0; i < 10; ++i)
        for (ll d = -9; d <= 9; ++d)
            gen(gen, "", 0, d, i);
    ll x;
    cin >> x;
    cout << *choices.lower_bound(x) << '\n';
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