// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (i < n - 1 && ((a[i] == '0' && a[i + 1] == '1' && b[i] == '1' && b[i + 1] == '0') || (b[i] == '0' && b[i + 1] == '1' && a[i] == '1' && a[i + 1] == '0')))
            ans++, ++i;
        else if (a[i] != b[i])
            ans++;
    }
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