// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

// vector<ll> y = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// vector<ll> pref(13, 0);
// partial_sum(y.begin(), y.end(), pref.begin() + 1);

void Solution() {
    vector<ll> pref = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    vector<ll> vals(500, 0);
    auto getNum = [&](ll month, ll day) -> ll {
        return 100 + pref[month - 1] + day;
    };

    ll n, m, d, p, t, xx;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> m >> d >> p >> t;
        xx = getNum(m, d) - 1;
        for (ll j = xx; j >= xx - t + 1; --j) vals[j] += p;
    }
    cout << *max_element(vals.begin(), vals.end()) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Solution();
    return 0;
}