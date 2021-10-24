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

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> likes(m);
    for (auto &x : likes) cin >> x;
    vector<ll> pos(n + 1), arr(n + 1), mini(n + 1), maxi(n + 1);
    fo(i, n + 1) arr[i] = mini[i] = maxi[i] = pos[i] = i;  // pos[x] = its position right now
    auto Set = [&](ll v, ll loc) {
        mini[v] = min(mini[v], loc);
        maxi[v] = max(maxi[v], loc);
    };
    for (auto x : likes) {
        if (pos[x] == 1) continue;
        ll t1 = arr[pos[x]];
        ll t2 = arr[pos[x] - 1];
        swap(pos[t1], pos[t2]);
        swap(arr[pos[t1]], arr[pos[t2]]);
        Set(t1, pos[t1]);
        Set(t2, pos[t2]);
        // dbg(arr, pos);
    }
    // dbg(maxi, mini);
    for (ll i = 1; i <= n; ++i) cout << mini[i] << ' ' << maxi[i] << '\n';
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

/**
 * 1 2 3 and 3 2 1 3 3
 * 1 2 3
 * 1 3 2
 * 1 2 3
 * 1 2 3
 * 1 3 2
 * 3 1 2
 * 
 * 
 * 1 2 3 4 5 6 7 8 9 10 and 7 3 5 7 3 6 
 * 1 2 3 4 5 6 7 8 9 10
 * 1 2 3 4 5 7 6 8 9 10
 * 1 3 2 4 5 7 6 8 9 10
 * 1 3 2 5 4 7 6 8 9 10
 * 1 3 2 5 7 4 6 8 9 10
 * 3 1 2 5 7 4 6 8 9 10
 * 3 1 2 5 7 6 4 8 9 10
*/