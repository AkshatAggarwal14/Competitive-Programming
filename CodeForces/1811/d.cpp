#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353
/**

function<bool(ll, ll, ll, ll, ll)> dfs = [&](ll minX, ll maxX, ll minY, ll maxY, ll level) {
    // at level 0, set Fn to left or right
    // at level 1, set Fn-1 to up or down
    // at level n, set F0 ...
    if (minX > x || maxX < x || minY > y || maxY < y) return false;
    ll setID = n - level;
    if (setID == 0) return true;
    ll setVal = F[setID];
    bool ans = false;
    if (level % 2 == 0) {
        // left
        ans |= dfs(minX + setVal, maxX, minY, maxY, level + 1);
        // right
        ans |= dfs(minX, maxX - setVal, minY, maxY, level + 1);
    } else {
        // up
        ans |= dfs(minX, maxX, minY + setVal, maxY, level + 1);
        // down
        ans |= dfs(minX, maxX, minY, maxY - setVal, level + 1);
    }
    dbg(ans);
    return ans;
};

*/

vector<ll> fib;
void test() {
    ll n_, x_, y_;
    cin >> n_ >> x_ >> y_, --x_, --y_;
    function<bool(ll, ll, ll)> check = [&](ll n, ll x, ll y) {
        if (n == 1) return true;
        if (y >= fib[n]) {
            y -= fib[n];
            return check(n - 1, y, x);
        } else if (fib[n + 1] - 1 - y >= fib[n]) {
            return check(n - 1, y, x);
        }
        return false;
    };
    cout << (check(n_, x_, y_) ? "YES\n" : "NO\n");
}

int32_t main() {
    fib.push_back(1);
    fib.push_back(1);
    while (fib.size() <= 50) {
        fib.push_back(fib.back() + fib[fib.size() - 2]);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
