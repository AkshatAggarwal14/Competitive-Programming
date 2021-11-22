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
    // The coordinates are always on the path
    string s;
    cin >> s;
    ll x = 0, y = 0;
    map<char, pair<ll, ll>> XY = {{'U', {0, 1}}, {'D', {0, -1}}, {'R', {1, 0}}, {'L', {-1, 0}}};
    for (ll i = 0; i < sz(s); ++i) {
        x += XY[s[i]].first, y += XY[s[i]].second;
        // try by putting obstacle on each point
        ll nx = 0, ny = 0;
        for (ll j = 0; j < sz(s); ++j) {
            if (nx + XY[s[j]].first == x && ny + XY[s[j]].second == y) continue;
            nx += XY[s[j]].first, ny += XY[s[j]].second;
        }
        if (nx == 0 && ny == 0) return void(cout << x << ' ' << y << '\n');
    }
    cout << "0 0\n";
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