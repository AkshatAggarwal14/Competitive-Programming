#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

void Solution() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> b(n);
    for (ll i = 0; i < n; ++i) cin >> b[i].first, b[i].second = i;
    sort(all(b));
    ll ctr = 0;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; ++i) {
        if (b[i].first > ctr) {
            a.push_back({ctr, b[i].second});
            ctr++;
        } else {
            a.push_back({b[i].first - 1, b[i].second});
        }
    }
    sort(all(a), [&](pair<ll, ll> A, pair<ll, ll> B) { return A.second < B.second; });
    for (auto &x : a) cout << x.first << ' ';
    cout << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}