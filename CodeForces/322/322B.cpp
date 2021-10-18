// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll r, g, b;
    cin >> r >> g >> b;
    ll ans = r / 3 + b / 3 + g / 3;
    if (min({r, b, g}) > 1) ans = max(ans, (r - 1) / 3 + (b - 1) / 3 + (g - 1) / 3 + 1);
    if (min({r, b, g}) > 2) ans = max(ans, (r - 2) / 3 + (b - 2) / 3 + (g - 2) / 3 + 2);
    cout << ans << '\n';
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