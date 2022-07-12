#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;

// calculate a^b mod m, use binary exponentiation
ll power(ll a, ll b, ll m = MOD) {
    ll res = 1, t = a;
    while (b) {
        if (b & 1) res = (res * t) % m;
        t = (t * t) % m;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll pw = power(b, c, MOD - 1);
        cout << power(a, pw) << '\n';
    }
}