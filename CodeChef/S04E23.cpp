#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void Solution() {
    ll n, p, q;
    string s;
    cin >> n >> p >> q >> s;
    bool dir = false;
    pair<ll, ll> y = {0, 0}, x = {0, 0};
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') dir = !dir;
        if (dir) {
            if (y.first > p)
                y.first--;
            else
                y.first++;
            if (x.second > q)
                x.second--;
            else
                x.second++;
        } else {
            if (y.second > q)
                y.second--;
            else
                y.second++;
            if (x.first > p)
                x.first--;
            else
                x.first++;
        }
    }
    cout << ((y.second == q and y.first == p) or (x.second == q and x.first == p) ? "Yes\n" : "No\n");
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