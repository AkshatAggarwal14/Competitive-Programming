#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n - 1), b(n - 1);
    for (ll i = 0; i < n - 1; ++i) cin >> a[i];
    for (ll i = 0; i < n - 1; ++i) cin >> b[i];
    vector<vector<pair<ll, ll>>> choose(n - 1);
    for (ll k = 0; k < n - 1; ++k) {
        bool flag = false;
        for (ll i = 0; i <= 3; ++i) {
            for (ll j = 0; j <= 3; ++j) {
                if ((i | j) == a[k] && (i & j) == b[k]) {
                    flag = true;
                    choose[k].emplace_back(i, j);  // storing choices for t[i] & t[i+1]
                }
            }
        }
        if (!flag) {  // can be no for a certain t[i] & t[i+1] if doesnt exist
            cout << "NO\n";
            return;
        }
    }
    dbg(choose);
    for (auto &[x, y] : choose[0]) {  // checking for each pair for 1st
        vector<ll> ans;
        ans.push_back(x);
        ans.push_back(y);
        ll i = 1;
        for (ll i = 1; i < n - 1; ++i) {
            bool flag = false;
            for (auto &[x, y] : choose[i]) {
                if (x == ans[i]) {
                    ans.push_back(y);  // if matches with last y then push
                    flag = true;
                }
            }
            if (!flag) break;  // if none then break, ans doesnt exist
        }
        dbg(ans);
        if (sz(ans) == n) {
            cout << "YES\n";
            for (auto &i : ans) cout << i << ' ';
            return;
        }
    }
    cout << "NO\n";
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    // ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}