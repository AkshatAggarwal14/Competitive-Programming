#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    string s = "123";
    function<void(ll, ll, ll)> dfs = [&](ll digs, bool tight, ll curNum) {
        if (digs == -1) {
            cout << curNum << '\n';
            return;
        }

        int ub = 9;
        if (tight) ub = s[2 - digs] - '0';

        for (int i = 0; i < ub; ++i) {
            dfs(digs - 1, false, curNum * 10 + i);
        }
        dfs(digs - 1, tight, curNum * 10 + ub);
    };

    dfs(2, true, 0);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    test();
    return 0;
}
