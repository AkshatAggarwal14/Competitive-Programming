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
    ll n, k;
    cin >> n >> k;
    deque<ll> dq;
    fo(i, n) dq.push_back(i + 1);
    vector<ll> v;
    fo(i, k) {
        v.push_back(dq.front());
        dq.pop_front();
    }
    if (sz(dq) == 1) return void(cout << -1 << '\n');
    ll f = dq.front();
    dq.pop_front();
    dq.push_back(f);
    for (ll i = k; i < n; ++i) {
        v.push_back(dq.front());
        dq.pop_front();
    }
    for (auto x : v) cout << x << ' ';
    cout << '\n';
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