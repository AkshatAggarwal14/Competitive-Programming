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
    string s;
    array<ll, 10> f{};
    cin >> n >> s;
    for (ll i = 1; i <= 9; ++i) cin >> f[i];
    ll st = -1, en = n;
    for (ll i = 0; i < n; ++i) {
        if (f[s[i] - '0'] > s[i] - '0') {
            st = i;
            break;
        }
    }
    for (ll i = st; i < n; ++i) {
        if (f[s[i] - '0'] < s[i] - '0') {
            en = i;
            break;
        }
    }
    if (st == -1) return void(cout << s << '\n');
    for (ll i = st; i < en; ++i) s[i] = char(f[s[i] - '0'] + '0');
    cout << s << '\n';
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