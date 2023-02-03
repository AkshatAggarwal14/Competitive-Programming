#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> left(n);
    for (int i = 0; i < n; ++i)
        left[i] = i + 1 + a[i];
    sort(left.begin(), left.end());
    int ans = 0;
    while (ans < n && c >= left[ans]) {
        c -= left[ans];
        ++ans;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}