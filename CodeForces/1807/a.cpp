#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << (a + b == c ? "+" : "-") << '\n';
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