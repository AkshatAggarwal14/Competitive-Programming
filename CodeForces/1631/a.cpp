#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll &A : a) cin >> A;
    for (ll &B : b) cin >> B;
    ll mx_a = *max_element(all(a));
    ll mx_b = *max_element(all(b));
    if (mx_b > mx_a) swap(a, b), swap(mx_a, mx_b);
    for (ll i = 0; i < n; ++i) {
        if (a[i] == mx_a) continue;
        if (b[i] > a[i]) swap(a[i], b[i]);
    }
    cout << (*max_element(all(a))) * (*max_element(all(b))) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}