// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    if (a + b + c <= d)
        ans = 1;
    else if (b + c <= d)
        ans = 2;
    else if (a + c <= d)
        ans = 2;
    else if (a + b <= d)
        ans = 2;
    else
        ans = 3;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
        Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}