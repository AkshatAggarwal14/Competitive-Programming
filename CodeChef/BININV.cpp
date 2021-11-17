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

ll inversions(string &s) {
    ll res = 0, count_1 = 0;
    for (ll i = 0; i < sz(s); ++i) {
        if (s[i] == '1')
            ++count_1;
        else
            res += count_1;
    }
    return res;
}

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x : v) cin >> x;
    sort(all(v), [&](string &a, string &b) {
        ll c00 = count(all(a), '0'), c01 = count(all(a), '1');
        ll c10 = count(all(b), '0'), c11 = count(all(b), '1');
        ll inc1 = c01 * c10, inc2 = c00 * c11;  // increase in inversions
        return inc1 < inc2;
    });
    string res = accumulate(all(v), string());
    cout << inversions(res) << '\n';
    dbg(v);
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