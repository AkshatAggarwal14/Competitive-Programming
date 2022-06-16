#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

string toTernary(ll n) {
    string s;
    while (n) {
        s.push_back(n % 3 + '0');
        n /= 3;
    }
    reverse(s.begin(), s.end());
    return s;
}

ll toDecimal(string s) {
    ll res = 0, temp = 1;
    for (ll i = sz(s) - 1; i >= 0; i--) {
        res += (temp * (s[i] - '0'));
        temp = temp * 3;
    }
    return res;
}

void Solution() {
    ll n;
    cin >> n;
    string s = toTernary(n);
    string ans = s;
    ll I = -1, J = -1;
    for (ll i = 0; i < sz(s); ++i) {
        if (s[i] == '0') {
            I = i;
        } else if (s[i] == '2') {
            J = i;
            break;
        }
    }
    if (J != -1) {      // 2 is present
        if (I == -1) {  // no 0 before 2
            ans = "1" + string(sz(s), '0');
        } else {
            ans[I] = '1';
            for (ll i = I + 1; i < sz(ans); ++i) ans[i] = '0';
        }
    }
    dbg(s, ans);
    cout << toDecimal(ans) << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}