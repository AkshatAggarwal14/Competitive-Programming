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

void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    str s;
    cin >> s;
    bool flag = false;
    ll i1 = s.find("AB"), i2 = s.rfind("BA");
    ll i3 = s.find("BA"), i4 = s.rfind("AB");
    if ((i1 == -1 || i2 == -1 || i2 == i1 + 1 || i1 == i2 + 1) && (i3 == -1 || i4 == -1 || i4 == i3 + 1 || i3 == i4 + 1)) return void(cout << "NO");
    cout << "YES";
    dbg(i1, i2, i3, i4);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}