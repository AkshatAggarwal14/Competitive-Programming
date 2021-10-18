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
    ll n, m, k;
    cin >> n >> m >> k;
    v<v<ll>> vv(n, v<ll>(m));

    fo(i, n) {
        fo(j, m) {
            cin >> vv[i][j];
        }
    }
    char q;
    ll I, J;
    vl r(n), c(m);
    fo(i, n) r[i] = i;
    fo(i, m) c[i] = i;
    fo(i, k) {
        cin >> q >> I >> J;
        if (q == 'c')
            swap(c[I - 1], c[J - 1]);
        else if (q == 'r')
            swap(r[I - 1], r[J - 1]);
        else
            cout << vv[r[I - 1]][c[J - 1]] << '\n';
    }
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