#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> int { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

/*
        G - B...
        |
    B - R - G - B
            |
        B - R
    any number of GB can be connected to R, and any number of RB can be connected to G.
*/

void Solution() {
    int R, G, B;
    cin >> R >> G >> B;
    if (B > R + G) return void(cout << "-1\n");
    string ans = "RG";
    vector<array<int, 2>> edges;
    edges.push_back({1, 2});
    ans.append(string(R - 1, 'R'));
    ans.append(string(G - 1, 'G'));
    ans.append(string(B, 'B'));
    for (int i = 3; i <= R + 1; ++i) edges.push_back({2, i});
    for (int i = R + 2; i <= R + G; ++i) edges.push_back({1, i});
    int pos = R + G + 1;
    for (int i = 1; i <= B; ++i) edges.push_back({i, pos++});
    cout << ans << '\n';
    for (auto &[x, y] : edges) cout << x << ' ' << y << '\n';
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