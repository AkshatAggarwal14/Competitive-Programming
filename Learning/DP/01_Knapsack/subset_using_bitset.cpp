#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
const ll INF = 1e9;

void test() {
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
    bitset<10000> dp;
    // dp[i] = true if it is possible to make a subset of given sum
    dp[0] = 1;
    for (int &i : arr)
        dp |= dp << i;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    test();
    return 0;
}
