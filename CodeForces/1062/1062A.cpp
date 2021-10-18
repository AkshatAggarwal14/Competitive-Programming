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
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n) cin >> a[i];
    if (n == 1) return void(cout << 0);
    vl temp;
    vvl ops;
    fo(i, n) {
        if (a[i + 1] - a[i] == 1)
            temp.emplace_back(a[i]);
        else {
            if (!temp.empty())
                ops.emplace_back(temp);
            temp.clear();
        }
    }
    sort(all(ops), [&](vl A, vl B) { return sz(A) > sz(B); });
    if (ops.empty()) return void(cout << 0);
    dbg(ops);
    ll ans = 0;
    for (vl vec : ops) {
        if (vec[sz(vec) - 1] == 999 || vec[0] == 1)
            ans = max(ans, sz(vec));
        else
            ans = max(ans, sz(vec) - 1);
    }
    cout << ans << '\n';
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