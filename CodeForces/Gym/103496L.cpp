#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, m, num, X = -1, Y = -1;
    char c, ndir;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &x : grid) cin >> x;
    ll q;
    cin >> q;
    while (q--) {
        cin >> c >> num;
        if (c == 'T') c = 'U';
        if (c == 'B') c = 'D';

        if (c == 'L') X = num - 1, Y = 0;
        if (c == 'R') X = num - 1, Y = m - 1;
        if (c == 'U') X = 0, Y = num - 1;
        if (c == 'D') X = n - 1, Y = num - 1;
        ndir = c;  // direction from which light incident
        while (X >= 0 && X < n && Y >= 0 && Y < m) {
            if (grid[X][Y] == '/') {
                if (ndir == 'L') {
                    --X;
                    ndir = 'D';
                } else if (ndir == 'R') {
                    ++X;
                    ndir = 'U';
                } else if (ndir == 'U') {
                    --Y;
                    ndir = 'R';
                } else {
                    ++Y;
                    ndir = 'L';
                }
            } else {
                if (ndir == 'R') {
                    --X;
                    ndir = 'D';
                } else if (ndir == 'L') {
                    ++X;
                    ndir = 'U';
                } else if (ndir == 'D') {
                    --Y;
                    ndir = 'R';
                } else {
                    ++Y;
                    ndir = 'L';
                }
            }
        }
        if (X == n) cout << "B " << Y + 1 << '\n';
        if (X == -1) cout << "T " << Y + 1 << '\n';
        if (Y == m) cout << "R " << X + 1 << '\n';
        if (Y == -1) cout << "L " << X + 1 << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}