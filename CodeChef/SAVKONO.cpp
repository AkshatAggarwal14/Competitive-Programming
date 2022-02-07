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

void Solution() {
    ll n, z, t;
    cin >> n >> z;
    multiset<ll> st;
    for (ll i = 0; i < n; ++i) cin >> t, st.insert(t);
    ll ans = 0;
    while (!st.empty()) {
        ll attack = *st.rbegin();
        if (z - attack < 0) return void(cout << ans + 1 << '\n');
        if (z - attack <= 0) return void(cout << ans << '\n');
        z -= attack;
        st.erase(st.lower_bound(attack));
        if (attack / 2) st.insert(attack / 2);
        ans++;
    }
    cout << "Evacuate\n";
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
    return 0;
}