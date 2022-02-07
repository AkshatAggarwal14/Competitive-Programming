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
    ll n, a, b;
    cin >> n >> a >> b;
    set<ll> st;
    for (ll i = 1; i <= n; ++i) st.insert(i);
    st.erase(a), st.erase(b);
    vector<ll> left = {a}, right = {b};
    for (ll i = 0; i < n / 2 - 1; ++i) {
        left.push_back(*st.rbegin());
        st.erase(*st.rbegin());
    }
    for (ll i = 0; i < n / 2 - 1; ++i) {
        right.push_back(*st.begin());
        st.erase(*st.begin());
    }
    ll mn = *ranges::min_element(left), mx = *ranges::max_element(right);
    if (mn == a && mx == b) {
        for (auto &x : left) cout << x << ' ';
        for (auto &x : right) cout << x << ' ';
    } else {
        cout << -1;
    }
    cout << '\n';
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