#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll L = 0, R = n + 1;
    while (R > L + 1) {
        ll M = (L + R) / 2;
        ll real = 0;
        cout << "? " << M << ' ';
        for (ll i = 1; i <= M; ++i) cout << i << ' ', real += a[i - 1];
        cout << endl;

        ll got;
        cin >> got;

        if (real != got) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << "! " << L + 1 << endl;
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