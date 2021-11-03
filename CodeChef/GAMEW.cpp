#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n;
    string s;
    cin >> n >> s;
    ll last = 1 - (s[0] - '0'), ctr = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == last) {
            continue;
        } else {
            ctr++;
            last = s[i];
        }
    }
    // ctr is number of groups
    // if they play optimally
    // groups | winner
    // 1|S, 2|R, 3|S,...
    if (ctr % 3 == 2)
        cout << "RAMADHIR\n";
    else
        cout << "SAHID\n";
}
/*
ll dp[N];
dp[1]=1;
dp[2]=0;
for(ll i=3;i<N;i++){
    dp[i]=min(dp[i-1],dp[i-2])^1;
}
*/

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    cerr << "Time:" << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}