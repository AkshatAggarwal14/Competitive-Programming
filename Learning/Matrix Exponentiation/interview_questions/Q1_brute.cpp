/*
you have a 20 length circular binary string
do this operation k times,

iterate i from 1 to 20
   if i-1th and i+1th characters are different, set si as 1 else 0

output string after k operations
*/

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
    string s;
    int k;
    cin >> s >> k;
    --k;
    int n = int(s.size());
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < n; i++) {
            if (s[(i - 1 + n) % n] != s[(i + 1) % n]) {
                s[i] = '1';
            } else {
                s[i] = '0';
            }
        }
        cout << s << "\n";
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}

/*
k=1, 001011
k=2, 100101
k=3, 110010
k=4, 111001
k=5, 011100
k=6, 101110
k=7, 010111
*/