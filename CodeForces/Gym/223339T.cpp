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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &X : a) cin >> X;
    bool flag = false;
    ll value = a[0];
    function<void(ll, ll)> recurse = [&](ll gap_no, ll val) {
        if (gap_no == n) { // base case is reaching the end of array
            if (val == x) flag = true;
            return;
        }
        recurse(gap_no + 1, val + a[gap_no]);
        recurse(gap_no + 1, val - a[gap_no]);
    };
    recurse(1, value);
    cout << (flag ? "YES" : "NO");
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
    Solution();
    return 0;
}