// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
ll n, m;
bool cmp(pair<string, ll> &s, pair<string, ll> &t) {
    // even - asc
    // odd - dsc
    ll i = 0;
    for (; i < m; ++i) {
        if (s.first[i] != t.first[i]) {
            if (i % 2 == 0)
                return s.first[i] < t.first[i];
            else
                return t.first[i] < s.first[i];
        }
    }
    return false;  // never reached
}

void Solution() {
    cin >> n >> m;
    vector<pair<string, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end(), cmp);
    // dbg(a);
    for (ll i = 0; i < n; ++i) cout << a[i].second << ' ';
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