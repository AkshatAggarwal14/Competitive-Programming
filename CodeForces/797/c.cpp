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
const int AL = 26;

void test() {
    string s, t, u;
    cin >> s;
    int n = sz(s);
    /*
        Find min element in s[i, n], let index = k
        Add elements until k into t, then pop elements from t until they are equal to top and add to u
        Add remaining from s to t, add remaining from t to u
    */
    vector<vector<int>> id(AL);
    for (int i = 0; i < n; ++i) id[s[i] - 'a'].push_back(i);
    for (int i = 0; i < AL; ++i) reverse(all(id[i]));

    for (int i = 0; i < n;) {
        int k = -1;
        for (int j = 0; j < AL; ++j) {
            if (id[j].empty()) continue;
            k = id[j].back();
            break;
        }
        while (!t.empty() && t.back() <= s[k]) {  // acdbd
            u += t.back();
            t.pop_back();
        }
        for (int j = i; j <= k; ++j) {
            id[s[j] - 'a'].pop_back();
            t += s[j];
        }
        while (!t.empty() && t.back() <= s[k]) {
            u += t.back();
            t.pop_back();
        }
        i = k + 1;
    }
    while (!t.empty()) {
        u += t.back();
        t.pop_back();
    }
    cout << u << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
