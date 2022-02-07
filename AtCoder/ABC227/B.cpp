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

//4ab+3a+3b
void Solution() {
    vector<bool> mark(1010, false);
    for (ll a = 1; a <= 1000; ++a) {
        for (ll b = 1; b <= 1000; ++b) {
            ll area = 4 * a * b + 3 * a + 3 * b;
            if (area > 1000) continue;
            mark[area] = true;
        }
    }
    ll n, ctr = 0;
    cin >> n;
    vector<ll> s(n);
    for (auto &x : s) cin >> x;
    for (auto &x : s) {
        if (!mark[x]) ctr++;
    }
    cout << ctr << '\n';
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