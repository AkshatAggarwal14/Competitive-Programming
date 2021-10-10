// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> adj(n);
    vector<ll> d_even(n, -1), d_odd(n, -1);  // distance from odd or even
    queue<ll> even, odd;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1)
            odd.emplace(i), d_odd[i] = 0;
        else
            even.emplace(i), d_even[i] = 0;
        // opposite as we inverse the graph to run bfs from other points
        if (i - a[i] >= 0) adj[i - a[i]].push_back(i);
        if (i + a[i] <= n - 1) adj[i + a[i]].push_back(i);
    }
    // for even elements
    while (!odd.empty()) {
        ll parent = odd.front();
        odd.pop();
        for (auto child : adj[parent]) {
            if (d_odd[child] == -1) {
                odd.emplace(child);
                d_odd[child] = d_odd[parent] + 1;
            }
        }
    }
    // for odd elements
    while (!even.empty()) {
        ll parent = even.front();
        even.pop();
        for (auto child : adj[parent]) {
            if (d_even[child] == -1) {
                even.emplace(child);
                d_even[child] = d_even[parent] + 1;
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << ((a[i] & 1) ? d_even[i] : d_odd[i]) << ' ';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}