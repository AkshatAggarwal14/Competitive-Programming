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
    vector<ll> a(n), cnt(3, 0);
    for (ll &x : a) cin >> x, x = x % 3, ++cnt[x];
    ll s = accumulate(all(a), 0LL);
    if (s % 3) return void(cout << -1 << '\n');
    ll moves = 0, t = 0;
    t = min(cnt[2], cnt[1]);
    moves += t;
    cnt[2] -= t, cnt[1] -= t;

    t = cnt[1] / 3;
    moves += 2 * t;
    cnt[1] -= 3 * t;

    t = cnt[2] / 3;
    moves += 2 * t;
    cnt[2] -= 3 * t;

    cout << moves << '\n';
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