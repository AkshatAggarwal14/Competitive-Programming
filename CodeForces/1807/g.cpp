#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a[0] != 1) return void(cout << "NO\n");
    ll sum = a[0];
    for (ll i = 1; i < n; ++i) {
        if (a[i] > sum) return void(cout << "NO\n");
        sum += a[i];
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}