// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

ll num(string s) {
    ll res = 0;
    for (ll i = 0; i < (ll)s.size(); ++i) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

void Solution() {
    string s;
    cin >> s;
    ll n = s.length();
    sort(s.begin(), s.end());
    ll ans = 0;
    do {
        if (s[0] == '0') continue;
        for (ll i = 0; i < n; ++i) {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            if (s1.length() == 0 || s2.length() == 0 || s1[0] == '0' || s2[0] == '0')
                continue;
            // dbg(s1, s2);
            ll res = num(s1) * num(s2);
            ans = max(ans, res);
        }
    } while (next_permutation(s.begin(), s.end()));
    // assert(ans != 0);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}