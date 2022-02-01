#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll((x).size()))
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

//http://www.usaco.org/index.php?page=viewproblem&cpid=1167
void Solution() {
    char guess[3][3], ans[3][3];
    vector<ll> cnt1(26, 0), cnt2(26, 0);
    for (ll i = 0; i < 3; ++i)
        for (ll j = 0; j < 3; ++j) cin >> ans[i][j], ++cnt1[ans[i][j] - 'A'];
    for (ll i = 0; i < 3; ++i)
        for (ll j = 0; j < 3; ++j) cin >> guess[i][j], ++cnt2[guess[i][j] - 'A'];
    ll green = 0, yellow = 0;
    for (ll i = 0; i < 3; ++i) {
        for (ll j = 0; j < 3; ++j) {
            if (ans[i][j] == guess[i][j]) {
                green++;
                --cnt1[ans[i][j] - 'A'];
                --cnt2[ans[i][j] - 'A'];
            }
        }
    }
    for (ll i = 0; i < 26; ++i) yellow += min(cnt1[i], cnt2[i]);
    cout << green << '\n';
    cout << yellow << '\n';
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