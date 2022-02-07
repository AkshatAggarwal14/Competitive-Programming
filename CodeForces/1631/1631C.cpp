#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void Solution() {
    ll n, k;
    cin >> n >> k;
    if (n == 4 && k == 3) return void(cout << "-1\n");  //!
    vector<ll> a, b;
    for (ll i = 0; i < n; ++i) ((i < n / 2) ? a : b).push_back(i);
    reverse(all(b));   // 0 1 2 3 and 7 6 5 4
    if (k == n - 1) {  // (n-1)&(n-2) = (n-2), 1&(n-3) = 1
        swap(a[1], b[0]);
        swap(b[0], a[2]);
    } else if (k < n / 2) {
        swap(a[0], a[k]);
    } else {
        swap(a[0], b[n / 2 - 1 - (k - n / 2)]);  // from end
    }
    for (ll i = 0; i < n / 2; ++i) {
        cout << a[i] << ' ' << b[i] << '\n';
        k -= ((a[i] & b[i]));
    }
    assert(k == 0);  // check
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}