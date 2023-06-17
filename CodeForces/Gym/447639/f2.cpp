#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e3 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

// ll dp[N][N][2];
// // {does player win if a in first and b in second}
// // {player: 0 -> salman, 1 -> abhishek}
// ll dfs(ll a, ll b, ll player) {
//     if (a == 0 && b == 0) return false;
//     ll &ans = dp[a][b][player];
//     if (ans != -1) return ans;
//     for (ll i = 1; i <= a; ++i) {
//         bool tans = dfs(a - i, b, player ^ 1);
//         if (!tans) return ans = 1;
//     }
//     for (ll i = 1; i <= b; ++i) {
//         bool tans = dfs(a, b - i, player ^ 1);
//         if (!tans) return ans = 1;
//     }
//     for (ll i = 1; i <= min(a, b); ++i) {
//         bool tans = dfs(a - i, b - i, player ^ 1);
//         if (!tans) return ans = 1;
//     }
//     return ans = 0;
// }

map<ll, ll> mp;
void test() {
    ll a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    if (b == mp[a]) return void(cout << "Abhishek Bachchan\n");
    cout << "Salman Khan\n";
    // now a is smaller than b
    // for (ll i = 0; i < 10; ++i) {
    //     for (ll j = i; j < 50; ++j) {
    //         cout << i << ' ' << j << ' ' << (dfs(i, j, 0) ? "Salman Khan" : "Abhishek Bachchan") << '\n';
    //     }
    //     cout << '\n';
    // }

    // (lower and upper Wythoff sequences)
    // https://oeis.org/search?q=0+2+1+5+7+3+10+4+13&language=english&go=Search
    // Abhishek only wins when this sequence
    // (n,a(n)) are Wythoff pairs: (0,0), (1,2), (3,5), (4,7), ..., where each difference occurs once.
}

int32_t main() {
    ll diff = 0;
    for (ll i = 0; i < N; ++i) {
        if (!mp.count(i)) {
            mp[i] = i + diff;
            mp[i + diff] = i;
            ++diff;
        }
    }
    dbg(mp);
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
