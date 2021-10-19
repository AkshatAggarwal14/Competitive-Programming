#ifndef ONLINE_JUDGE
// https://github.com/AkshatAggarwal14/Competetive-Programming/tree/master/CodeForces
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto& container) -> ll { return container.size(); };

void findNumbers(vector<ll>& ar, ll sum, vector<vector<ll>>& res, vector<ll>& r, ll i) {
    if (sum == 0) {
        res.push_back(r);
        return;
    }
    while (i < sz(ar) && sum - ar[i] >= 0) {
        r.push_back(ar[i]);
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;
        r.pop_back();  // backtrack shit
    }
}

vector<vector<ll>> combinationSum(vector<ll>& ar, ll sum) {
    sort(ar.begin(), ar.end());
    ar.erase(unique(ar.begin(), ar.end()), ar.end());
    vector<ll> r;
    vector<vector<ll>> res;
    findNumbers(ar, sum, res, r, 0);
    return res;
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    // calculates XOR for given 'use' vector
    auto calc = [&](vector<ll> A) {
        ll XOR = 0, i = 0, j = 0;
        while (j < n) {
            ll temp = 0;
            while (A[i] > 0) {
                temp = (temp | a[j]);
                A[i] -= 1, j++;
            }
            XOR = (XOR ^ temp);
            i++;
        }
        return XOR;
    };
    vector<ll> num;
    for (ll i = 1; i <= n; ++i) num.push_back(i);
    vector<vector<ll>> ans = combinationSum(num, n);  // generate all combos with given sum
    ll res = LLONG_MAX;
    dbg(sz(ans));
    for (auto& vv : ans) {
        vector<ll> temp = vv;
        do {
            res = min(res, calc(temp));
        } while (next_permutation(temp.begin(), temp.end()));
    }
    cout << res << '\n';
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