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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);

    int i = 0, j = 0, x = 0, ans = -1;

    /**
     * (ai ^ x) & (aj ^ x) = maximum
     *  1    0     1    0      1
     *  0    1     0    1      1
     *
     * Can set x to 0 or 1, but if a[i] and a[j] bit arent equal then maximum contains digit 0 only
     *  0    0     1    0      0
     *  1    1     0    1      0
     */
    function<void(vector<int> &, int, int, int)> DnC =
        [&](vector<int> &id, int bit, int curans, int curx) {
            if (id.size() <= 1) return;

            if (bit < 0) {
                if (curans > ans) {
                    ans = curans;
                    i = id[0], j = id[1];
                    x = curx;
                }
                return;
            }

            vector<int> curBitOn, curBitOff;
            for (auto &index : id)
                if ((a[index] >> bit) & 1)
                    curBitOn.push_back(index);
                else
                    curBitOff.push_back(index);

            if (curBitOff.size() == 1 && curBitOn.size() == 1) {
                DnC(id, bit - 1, curans, curx | (1 << bit));
                // DnC(id, bit - 1, curans, curx); // same answer
            } else {
                DnC(curBitOn, bit - 1, curans | (1 << bit), curx);
                DnC(curBitOff, bit - 1, curans | (1 << bit), curx | (1 << bit));
            }
        };

    DnC(ids, k - 1, 0, 0);
    cout << i + 1 << ' ' << j + 1 << ' ' << x << '\n';
}

int32_t main() {
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
