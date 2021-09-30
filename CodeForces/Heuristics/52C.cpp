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

string toBinary(ll n) {
    string s = bitset<64>(n).to_string();
    const auto pos = s.find('1');
    if (pos != string::npos)
        return s.substr(pos);
    return "0";
}

ll toDecimal(string s) {
    ll res = 0, temp = 1;
    for (ll i = sz(s) - 1; i >= 0; i--) {
        if (s[i] == '1') res += temp;
        temp = temp * 2;
    }
    return res;
}

void Solution() {
    ll n;
    cin >> n;
    string s = toBinary(n);
    auto it = s.find("10");
    if (it != string::npos) {
        s[it] = '0';
        s[it + 1] = '1';
        for (ll i = it + 1; i < sz(s); ++i)
            if (s[i] == '0')
                s[i] = '1';
        dbg(s);
    }
    cout << n - toDecimal(s) << '\n';
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
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}