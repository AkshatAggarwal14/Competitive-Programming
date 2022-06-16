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
const ll N = 1e7 + 5;
const ll MOD = 1'000'000'007;  // 998'244'353

vector<ll> spf(N + 1, -1);
void fill() {
    for (ll i = 2; i < N; ++i) {
        if (spf[i] == -1) {
            for (ll j = i * i; j < N; j += i) {
                spf[j] = i;
            }
        }
    }
}

vector<ll> factorise(ll &n) {
    vector<ll> res;
    while (spf[n] != -1) {
        ll fac = spf[n], cnt = 0;
        while (n % fac == 0) {
            ++cnt;
            n /= fac;
        }
        if (cnt) res.push_back(fac);
    }
    if (n > 1) res.push_back(n);
    return res;
}

void test() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll &X : x) cin >> X;
    vector<ll> cnt(N, 0);  // count of indexes that divide i -> prime number
    for (ll i = 0; i < n; ++i) {
        auto C = factorise(x[i]);
        for (ll &c : C) ++cnt[c];
    }
    vector<ll> pref(N, 0);
    for (ll i = 1; i < N; ++i) pref[i] = pref[i - 1] + cnt[i];
    ll m;
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        if (l >= N)
            cout << "0\n";
        else
            cout << pref[min(r, N - 1)] - pref[l - 1] << '\n';
    }
}

int32_t main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}