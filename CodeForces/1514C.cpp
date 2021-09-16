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

vector<bool> ok(1e5 + 5);
void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    ll n;
    cin >> n;
    ll prod = 1;
    for (ll i = 1; i < n; i++) {
        if (gcd(n, i) == 1) {
            ok[i] = true;
            prod = (prod * i) % n;
        }
    }
    if (prod != 1)
        ok[prod] = false;
    cout << count(1 + all(ok), true) << '\n';
    for (ll i = 1; i <= n; ++i)
        if (ok[i]) cout << i << " ";
    cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    // cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}