#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

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
    ll n;
    cin >> n;
    vector<ll> a(n);
    set<ll> has;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        has.insert(a[i]);
    }
    sort(all(a));
    for (ll i = 0; i < n - 2; ++i) {
        ll sum = a[i] + a[i + 1] + a[i + 2];
        if (!has.count(sum)) return void(cout << "NO\n");
    }
    for (ll i = 1; i < n - 1; ++i) {
        ll sum = a[0] + a[i] + a[i + 1];
        if (!has.count(sum)) return void(cout << "NO\n");
    }

    ll tries = 50;
    while (tries--) {
        for (ll i = 0; i < n - 2; ++i) {
            ll j = uid(i + 1, n - 2);
            ll k = uid(j + 1, n - 1);
            if (!has.count(a[i] + a[j] + a[k])) return void(cout << "NO\n");
        }
    }
    reverse(all(a));
    for (ll i = 0; i < n - 2; ++i) {
        ll sum = a[i] + a[i + 1] + a[i + 2];
        if (!has.count(sum)) return void(cout << "NO\n");
    }
    for (ll i = 1; i < n - 1; ++i) {
        ll sum = a[0] + a[i] + a[i + 1];
        if (!has.count(sum)) return void(cout << "NO\n");
    }

    tries = 50;
    while (tries--) {
        for (ll i = 0; i < n - 2; ++i) {
            ll j = uid(i + 1, n - 2);
            ll k = uid(j + 1, n - 1);
            if (!has.count(a[i] + a[j] + a[k])) return void(cout << "NO\n");
        }
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
