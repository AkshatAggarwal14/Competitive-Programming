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
    vector<ll> a(n), mark(n, 0), vals;
    for (ll &x : a) cin >> x;
    for (ll i = 1; i < n - 1; ++i)
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) mark[i] = 1;
    // go through all possible lens of groups, and check each config.
    // push valid lengths and find max n/len
    for (ll len = 1; len * len <= n; ++len) {
        // len of 1 group
        if (n % len == 0) {
            bool flag = true;
            for (ll st = 0; st < n; st += len) {
                ll cnt = 0;
                for (ll i = st; i < st + len; ++i)
                    if (mark[i]) cnt++;
                if (!cnt) flag = false;
            }
            if (flag) vals.push_back(n / len);
            // other divisor
            ll t = n / len;
            flag = true;
            for (ll st = 0; st < n; st += t) {
                ll cnt = 0;
                for (ll i = st; i < st + t; ++i)
                    if (mark[i]) cnt++;
                if (!cnt) flag = false;
            }
            if (flag) vals.push_back(len);
        }
    }
    if (vals.empty()) return void(cout << 0 << '\n');
    cout << *max_element(all(vals)) << '\n';
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