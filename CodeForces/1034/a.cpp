#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll N = 1'50'00'000;
vector<ll> spf(N + 1);
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

vector<ll> factorise(const ll &n) {
    vector<ll> res;
    ll temp = n;
    while (temp != 1) {
        int t = spf[temp];
        res.push_back(t);
        while (temp % t == 0) {
            temp /= t;
        }
    }
    return res;
}

void test() {
    int n;
    cin >> n;
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i], g = gcd(g, a[i]);

    for (int i = 0; i < n; ++i)
        a[i] /= g;

    unordered_map<int, int> div;
    for (int i = 0; i < n; ++i) {
        auto C = factorise(a[i]);
        for (auto &factor : C) {
            ++div[factor];
        }
    }

    int mx = 0;
    for (auto &[x, y] : div) {
        mx = max(mx, y);
    }

    dbg(div);

    cout << (mx ? n - mx : -1) << '\n';
}

int32_t main() {
    fill();
    dbg(pr.size());
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
