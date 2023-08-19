#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string randomString(ll length) {
    string res = "";
    for (ll i = 0; i < length; ++i) {
        ll choice = uid(0, int(alphabet.length()) - 1);
        res += alphabet[choice];
    }
    return res;
}

void test() {
    cout << "1\n";
    ll m = uid(1, ll(100));
    ll k = uid(2, ll(100));
    ll a1 = uid(0, ll(100));
    ll ak = uid(0, ll(100));
    cout << m << ' ' << k << ' ' << a1 << ' ' << ak << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
