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
    ll n;
    cin >> n;
    vector<ll> a(n);
    deque<ll> pos, idx;
    map<ll, ll> cnt;
    fo(i, n) {
        cin >> a[i];
        ++cnt[a[i]];
        if (a[i] == 0) idx.push_back(i);
    }
    ll use1 = idx.front(), use2 = idx.back();
    for (ll i = 1; i <= n; ++i) {
        if (!cnt.count(i)) pos.push_back(i);
    }
    dbg(pos);
    while (sz(pos)) {
        a[idx.front()] = pos.back();
        a[idx.back()] = pos.front();
        pos.pop_back();
        pos.pop_front();
        idx.pop_back();
        idx.pop_front();
        if (sz(pos) == 1) break;
    }
    dbg(pos, a);
    if (sz(pos) == 1) {
        a[idx.front()] = pos.front();
        swap(a[idx.front()], a[use1]);
    }
    fo(i, n) {
        if (a[i] == i + 1) {
            swap(a[i], a[use1]);
        }
    }
    fo(i, n) {
        if (a[i] == i + 1) {
            swap(a[i], a[use2]);
        }
    }
    for (auto x : a) cout << x << ' ';
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