/**
 *    author:  master._.mind
 *    created: 2022.06.20 20:48:03
 **/

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

constexpr ll N = 1e7;
array<ll, N + 1> smallest;
void fill() {
    array<ll, N + 1> sum;
    for (ll i = 1; i <= N; ++i) sum[i] = 1, smallest[i] = -1;
    for (ll i = 2; i <= N; ++i) {
        for (ll j = i; j <= N; j += i) {
            sum[j] += i;
        }
    }
    for (ll i = 1; i <= N; ++i) {
        if (sum[i] <= N && smallest[sum[i]] == -1) smallest[sum[i]] = i;
    }
}

void test() {
    ll n;
    cin >> n;
    cout << smallest[n] << '\n';
}

int32_t main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}