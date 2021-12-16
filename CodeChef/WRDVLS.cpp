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

/*
3 choose krne hai
indices with 3 = 2, 6, 8, 11, 14
(0, 8) ..
(2, 8)
(2, 9)
(2, 10)

(6, 11)
(6, 12)
(6, 13)
(3, 11)
(4, 11)
(5, 11)...

.. so on
*/

void Solution() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    unordered_map<ll, vector<ll>> idx;  // store indexes of all
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        idx[v[i]].push_back(i);
    }
    ll sum = 0;
    for (const auto &[i, _] : idx) {
        // Let's Work on every i
        for (ll j = 0; j < sz(idx[i]) - i + 1; ++j) {
            ll front;
            if (j == 0) {
                front = idx[i][j] + 1;  // 0 -> first idx
            } else {
                front = idx[i][j] - idx[i][j - 1];  // first -> second idx
            }
            if (j == sz(idx[i]) - i) {
                sum += (n - idx[i][j + i - 1]) * front * i;  // last idx -> n
            } else {
                sum += front * i * (idx[i][j + i] - idx[i][j + i - 1]);  // second last -> last idx
            }
        }
    }
    cout << sum << '\n';
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