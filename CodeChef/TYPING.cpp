#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
using str = string;
template <class T>
using v = vector<T>;
using vl = v<ll>;
using vvl = v<vl>;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll calc(str s) {
    ll ans = 2, n = sz(s);
    for (ll i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            ans += 4;
        else
            ans += 2;
    }
    return ans;
}

// Replaces d and f with 1, j and k with 2
void Modify(str &s) {
    fo(i, sz(s)) {
        if (s[i] == 'd' || s[i] == 'f')
            s[i] = '1';
        else
            s[i] = '2';
    }
}

void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    map<str, ll> used;  //stores time for first occurence
    ll n;
    cin >> n;
    str s, s1;
    ll ans = 0;
    fo(i, n) {
        cin >> s;
        s1 = s;
        Modify(s);  //replace with '1' and '2' //! this step can make 2 strs equal so just use it to calculate result
        if (used.count(s1)) {
            ans += used[s1] / 2;  //if already occured add time/2
        } else {
            used[s1] = calc(s);  //calculate time for first occurence
            ans += used[s1];     //add time for first occurence
        }
    }
    dbg(used);
    cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}