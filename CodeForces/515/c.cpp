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
    array<ll, 10> cnt = {0};
    ll n;
    string s;
    cin >> n >> s;
    for (char &c : s) {
        if (c == '2' || c == '3' || c == '5' || c == '7') ++cnt[c - '0'];  //primes
        if (c == '4') ++cnt[3], cnt[2] += 2;
        if (c == '6') ++cnt[5], ++cnt[3];
        if (c == '8') ++cnt[7], cnt[2] += 3;
        if (c == '9') ++cnt[7], ++cnt[2], cnt[3] += 2;
    }
    for (ll i = 9; i >= 2; --i)
        if (cnt[i]) cout << string(cnt[i], char(i + '0'));
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}