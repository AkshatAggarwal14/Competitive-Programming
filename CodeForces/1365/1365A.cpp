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
    ll n, m, num;
    cin >> n >> m;
    vl row(n, 0), col(m, 0);
    fo(i, n) {
        fo(j, m) {
            cin >> num;
            if (num == 1) row[i] = 1, col[j] = 1;
        }
    }
    ll unoccupied = min(n - accumulate(all(row), 0LL), m - accumulate(all(col), 0LL));
    if (unoccupied % 2)
        cout << "Ashish\n";
    else
        cout << "Vivek\n";
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