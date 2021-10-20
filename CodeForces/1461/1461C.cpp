#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, long double>> xp;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<ll> srt(a);
    ranges::sort(srt);
    ll mx = -1;
    for (ll i = 0; i < n; ++i)
        if (a[i] != srt[i]) mx = i;
    for (ll i = 0; i < m; ++i) {
        ll u;
        long double v;
        cin >> u >> v;
        if (u >= mx + 1) xp.emplace_back(u, v);
    }
    if (mx == -1) return void(cout << 1.0 << '\n');  // already sorted
    if (xp.empty()) return void(cout << 0.0 << '\n');
    ranges::sort(xp);
    vector<long double> A, B;
    for (ll i = 0; i < sz(xp); ++i) {
        A.push_back(xp[i].second);
        B.push_back(1.0 - xp[i].second);
    }
    for (ll i = 1; i < sz(xp); ++i) B[i] *= B[i - 1];
    long double ans = A[0];
    for (ll i = 1; i < sz(xp); ++i) ans += A[i] * B[i - 1];
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout<< fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((long double)clock()) / (long double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}