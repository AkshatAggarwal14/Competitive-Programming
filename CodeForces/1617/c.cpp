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
    set<ll> st;
    multiset<ll> rem;
    for (ll i = 1; i <= n; ++i) st.insert(i);
    for (ll &x : a) {
        cin >> x;
        if (st.contains(x)) {
            st.erase(x);
        } else {
            rem.insert(x);
        }
    }
    ll ans = 0;
    while (!rem.empty()) {
        ll n_2 = *st.begin();
        ll n_ = *rem.begin();
        if (n_ < n_2) return void(cout << -1 << '\n');
        if ((n_ % (n_ - n_2) != n_2)) return void(cout << -1 << '\n');
        st.erase(st.lower_bound(n_2));
        rem.erase(rem.lower_bound(n_));
        ++ans;
    }
    cout << ans << '\n';
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