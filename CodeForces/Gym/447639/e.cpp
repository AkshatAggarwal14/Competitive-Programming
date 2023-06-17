#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353;

const ll N = 10000;
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

// Returns a vector containing all the prime factors of n (25 --> 5, 5)
vector<pair<ll, ll>> prime_factorisation(ll n, ll p) {
    map<ll, ll> cnt;
    while (n != 1) {
        ++cnt[spf[n]];
        n /= spf[n];
    }
    vector<pair<ll, ll>> res;
    for (auto &[x, y] : cnt) {
        if (y % p) {
            res.push_back({x, y % p});
        }
    }
    return res;
}

void test() {
    ll n, p;
    cin >> n >> p;
    vector<vector<pair<ll, ll>>> r(n);
    for (auto &x : r) {
        ll num;
        cin >> num;
        x = prime_factorisation(num, p);
    }
    ll ans = 0;
    map<vector<pair<ll, ll>>, ll> mp;
    for (ll i = 0; i < n; ++i) {
        auto opp = r[i];
        for (auto &[x, y] : opp) {
            y = p - y;
        }
        ans += mp[opp];
        dbg(r[i], opp);
        ++mp[r[i]];
    }
    cout << ans << '\n';
    dbg(r);
}

int32_t main() {
    fill();
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
