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

// http://www.usaco.org/index.php?page=viewproblem&cpid=1168
void Solution() {
    auto checkwin = [](vector<ll> X, vector<ll> Y) {
        // true if X wins from Y, else false
        ll win_x = 0, win_y = 0;
        for (ll x = 0; x < 4; ++x) {
            for (ll y = 0; y < 4; ++y) {
                if (X[x] > Y[y])
                    win_x++;
                else if (Y[y] > X[x])
                    win_y++;
            }
        }
        return win_x > win_y;
    };

    auto non_transitive = [&](vector<ll> A, vector<ll> B, vector<ll> C) {
        // abc, acb
        return ((checkwin(A, B) && checkwin(B, C) && checkwin(C, A)) || (checkwin(A, C) && checkwin(C, B) && checkwin(B, A)));
    };
    vector<ll> a(4), b(4);
    for (ll i = 0; i < 4; ++i) cin >> a[i];
    for (ll i = 0; i < 4; ++i) cin >> b[i];
    dbg(a, b);
    for (ll i = 1; i <= 10; ++i) {
        for (ll j = 1; j <= 10; ++j) {
            for (ll k = 1; k <= 10; ++k) {
                for (ll l = 1; l <= 10; ++l) {
                    vector<ll> c = {i, j, k, l};
                    if (non_transitive(a, b, c)) return void(cout << "yes\n");
                }
            }
        }
    }
    cout << "no\n";
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