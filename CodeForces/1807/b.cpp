#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n;
    cin >> n;
    ll m = 0, b = 0;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
        if (x & 1)
            b += x;
        else
            m += x;
    }
    cout << (m > b ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}