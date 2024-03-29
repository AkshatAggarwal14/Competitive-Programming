#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 1'00'00'00;
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

vector<ll> prime_factorisation(ll n) {
    vector<ll> ans;
    while (n != 1) {
        ans.push_back(spf[n]);
        n /= spf[n];
    }
    return ans;
}

template <typename T, typename T_iterable>
vector<pair<T, ll>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, ll>> encoded;
    ll count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    map<ll, ll> cnt;
    for (auto &x : a) {
        auto p = compress<ll>(prime_factorisation(x));
        for (auto &[pri, count] : p) {
            cnt[pri] += count;
        }
    }

    for (auto &[x, y] : cnt) {
        if (y % n != 0) return void(cout << "NO\n");
    }

    cout << "YES\n";
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
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
