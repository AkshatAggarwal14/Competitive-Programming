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
const int INF = 1e9;

void Solution() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A) cin >> a;
    int best = INF;
    // max 1s = 2, as 3 makes a 3
    // max 2s = 2, as 3 makes a 6 = 2 * 3
    for (int ones = 0; ones <= 2; ones++) {
        for (int twos = 0; twos <= 2; twos++) {
            int threes = 0;
            for (int &item : A) {
                int least = INF;
                for (int x = 0; x <= ones; x++) {
                    for (int y = 0; y <= twos; y++) {
                        int need = item - x - 2 * y;
                        if (need >= 0 && need % 3 == 0) amin(least, need / 3);
                    }
                }
                amax(threes, least);
            }
            amin(best, ones + twos + threes);
        }
    }
    cout << best << '\n';
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