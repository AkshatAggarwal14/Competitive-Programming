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

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    ll n;
    string s;
    cin >> n >> s;
    ll moves = 0;
    ll i = 0;
    while (i < n - 1) {
        if (s[i] == '(' and s[i + 1] == '(') moves++, i += 2;
        if (s[i] == '(' and s[i + 1] == ')') moves++, i += 2;
        if (s[i] == ')' and s[i + 1] == ')') moves++, i += 2;
        if (s[i] == ')' and s[i + 1] == '(') {
            ll j;
            bool flag = false;
            for (j = i + 1; j < n; j++) {
                if (s[j] == ')') {
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
            i = j + 1;
            moves++;
        }
    }
    cout << moves << ' ';
    ll rem = n - 1 - i + 1;
    cout << rem << '\n';
}

int32_t main() {
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