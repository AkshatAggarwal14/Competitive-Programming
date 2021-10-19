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

vector<vector<ll>> ans;
void backtrack(vector<ll> a, ll sum) {
    if (sum == 0) {
        ans.push_back(a);
        return;
    }
    for (ll ele = 1; ele <= sum; ++ele) {
        a.push_back(ele);
        backtrack(a, sum - ele);
        a.pop_back();
    }
}

void Contest() {
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
    ll res = LLONG_MAX;
    backtrack(vector<ll>{}, n);
    for (vector<ll>& vv : ans) res = min(res, calc(vv));
    cout << res << '\n';
}

void Upsolve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ll res = LLONG_MAX;
    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll ored = 0, xored = 0;
        for (ll i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                xored ^= ored;
                ored = 0;
            }
            ored |= a[i];
        }
        xored ^= ored;
        res = min(res, xored);
    }
    cout << res;
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
    // Contest();
    Upsolve();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}