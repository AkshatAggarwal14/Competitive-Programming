#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

ll median(vector<ll> x) {
    sort(x.begin(), x.end());
    //point with the smallest summary distance is between left and right median.
    return x[sz(x) / 2] - x[(sz(x) - 1) / 2] + 1;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) cin >> x[i] >> y[i];
    cout << median(x) * median(y) << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}