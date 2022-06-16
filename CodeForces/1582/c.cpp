#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

void Solution() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st(all(s));
    ll ans = LLONG_MAX;
    for (char c : st) {
        ll L = 0, R = n - 1, cnt = 0;
        bool flag = true;
        while (L < R) {
            if (s[L] == s[R]) {
                cnt += 2;
                L++, R--;
            } else {
                if (s[L] != c and s[R] != c) {
                    flag = false;
                    break;
                }
                if (s[L] == c) L++;
                if (s[R] == c) R--;
            }
        }
        if (L == R) cnt++;
        if (flag) ans = min(ans, n - cnt);
    }
    ans = (ans == LLONG_MAX ? -1 : ans);
    cout << ans << '\n';
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
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}