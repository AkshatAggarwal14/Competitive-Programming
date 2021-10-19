#include "Akshat.hpp"
using ll = int64_t;

void Solution() {
    ll n;
    cin >> n;
    set<vector<ll>> res;
    for (ll mask = 0; mask < (1LL << n); mask++) {
        ll cnt = 0;
        vector<ll> temp;
        for (ll i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                if (cnt) temp.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        if (cnt) temp.push_back(cnt);
        res.insert(temp);
    }
    dbg(res);
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    return 0;
}