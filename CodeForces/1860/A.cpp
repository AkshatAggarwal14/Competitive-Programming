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
    cin >> s;
    int n = int(s.size());
    string s1(string(n, '(') + string(n, ')')), s2;
    for (int i = 0; i < n; ++i) s2 += "()";

    if (s1.find(s) == string::npos) {
        cout << "YES\n";
        cout << s1 << '\n';
        return;
    }
    if (s2.find(s) == string::npos) {
        cout << "YES\n";
        cout << s2 << '\n';
        return;
    }
    cout << "NO\n";
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
