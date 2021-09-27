#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

void Solution() {
    string s, t;
    cin >> s >> t;
    vector<ll> cnt(26, 0), pos;
    fo(i, sz(s)) {
        if (s[i] == '?')
            pos.push_back(i);
        else
            cnt[s[i] - 'a']++;
    }
    while (true) {
        for (char c : t) {
            if (cnt[c - 'a'] != 0)
                cnt[c - 'a']--;
            else if (!pos.empty())
                s[pos.back()] = c, pos.pop_back();
            else
                goto finish;
        }
    }
finish:
    cout << s << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}