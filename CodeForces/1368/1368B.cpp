// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
vector<ll> vals = {0};

void fill() {
    ll i = 1, term = 1;
    while (term < 1e16 + 5) {
        term = static_cast<ll>(pow(i, 10));
        vals.push_back(term);
        i++;
    }
}

void Solution() {
    ll k;
    cin >> k;
    ll ctr = 0;
    for (ll i = 0; i < (ll)vals.size() - 1; ++i) {
        if (vals[i + 1] > k) break;
        ctr++;
    }
    vector<ll> ok(10, ctr);
    ll P = static_cast<ll>(pow(ctr, 10));
    for (ll i = 0; i < 10; ++i) {
        if (P >= k) break;
        P /= ok[i];
        ok[i]++;
        P *= ok[i];
    }
    // dbg(ok);
    string ans = "codeforces";
    for (ll i = 0; i < 10; ++i) {
        for (ll j = 0; j < ok[i]; ++j) {
            cout << ans[i];
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fill();
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}