// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, ans = 1, num, sum = 0;
    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        if (sum + num > m) sum = 0, ans++;
        sum += num;
    }
    cout << ans << '\n';
    return 0;
}