#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...) 42
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

void Solution() {
    ll X = 1e18 + 100;  // larger than n
    cout << "?" << X << endl;
    ll rem;  // rem belongs to [0, n - 1]
    cin >> rem;
    // X - rem is a multiple of n
    // X - rem - 1 == n*k - 1 == n-1 mod n
    cout << "?" << X - rem - 1 << endl;
    ll ans;
    cin >> ans;
    cout << "!" << ans + 1 << endl;
}

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