#include <bits/stdc++.h>
// #include <Akshat.hpp>
using namespace std;

using ll = long long;
constexpr int N = 1e6;
// constexpr int N = 20;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> present(N + 1);
    for (int &A : a) cin >> A, ++present[A];
    ll ans = 1;
    for (ll i = N; i >= 2; --i) {
        if (present[i] >= 2) {
            cout << i << '\n';
            return 0;
        }
        ll cnt = 0;
        for (ll j = i; j <= N; j += i) {
            cnt += present[j];
            if (cnt >= 2) break;
        }
        if (cnt >= 2) {
            cout << i << '\n';
            return 0;
        };
    }
    cout << ans << '\n';
}