#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
constexpr auto sz = [](const auto &container) -> int { return int(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;
const int N = 200;

void Solution() {
    // use int to avoid MLE
    // For some a_i, find max number of a_j's present between when you take 1 a_i from left and 1 from right
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &A : a) cin >> A;
    vector<vector<int>> pos(N + 1), pref(N + 1, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
        pref[a[i]][i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j < n; ++j) {
            pref[i][j] += pref[i][j - 1];
        }
    }
    auto count_of = [&](int value, int L, int R) -> int {
        // between L and R
        L++, R--;
        if (L > R) return 0LL;
        return pref[value][R] - pref[value][L - 1];
    };
    int best = 1;
    for (int A = 1; A <= N; ++A) {
        int l = 0, r = sz(pos[A]) - 1;
        int ans = 1;
        while (l < r) {
            for (int B = 1; B <= N; ++B) {
                int y = count_of(B, pos[A][l], pos[A][r]);
                if (y > 0 || (B == A)) amax(ans, 2 * (l + 1) + y);
            }
            ++l, --r;
        }
        amax(best, ans);
    }
    cout << best << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}