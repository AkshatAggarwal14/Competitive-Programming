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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll res = 0, mx = -1, mn = -1;
    auto value = [&](ll x) -> ll { return (mx - x) * (x - mn); };
    set<ll> st;
    for (ll i = 0; i < n; i++) {
        mx = a[i], mn = a[i];
        st.clear();
        for (ll j = i; j < n; j++) {
            st.insert(a[j]);
            amax(mx, a[j]), amin(mn, a[j]);
            if (j - i < 2) continue;

            ll inc = 0;
            auto it = st.lower_bound((mx + mn) / 2);
            // calculate for both values near mean
            if (it != st.begin()) amax(inc, value(*(it--)));
            if (it != st.end()) amax(inc, value(*it));
            res += inc;
        }
    }
    cout << res << '\n';
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