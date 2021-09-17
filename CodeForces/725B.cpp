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
    // window to aisle
    map<char, ll> vals = {
        {'f', 1},
        {'e', 2},
        {'d', 3},
        {'a', 4},
        {'b', 5},
        {'c', 6},
    };
    str s;
    cin >> s;
    stringstream ss(s);
    ll seat_no;
    char seat;
    ss >> seat_no >> seat;
    ll prev = (seat_no / 4);  // previous block of 4
    if (4 * prev == seat_no) prev--;
    ll ans = 16 * prev;  //6 serving + 1 moving in block + 1 moving to next block
    ll rem = seat_no - prev * 4;
    if (rem == 2 || rem == 4) ans += 7;  //6 serving + 1 moving
    ans += vals[seat];
    cout << ans << '\n';
    dbg(seat_no, seat, prev, rem);
}

void Solve() {
    string use = "-fedabc";
    ll seat_no;
    char seat;
    cin >> seat_no >> seat;
    ll prev = (seat_no / 4);  // previous block of 4
    if (4 * prev == seat_no) prev--;
    ll ans = 16 * prev;
    //2 * (6 serving + 1 moving in block + 1 moving to next block)
    ll rem = seat_no - prev * 4;
    if (rem == 2 || rem == 4) ans += 7;  //6 serving + 1 moving
    ans += ll(use.find(seat));
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
    for (ll i = 1; i <= tc; ++i) Solve();
    return 0;
}