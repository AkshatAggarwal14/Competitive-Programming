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

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

void test() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> frq(26);
    for (char c : s) frq[c - 'a']++;
    string res(n, ' ');
    vector<array<int, 2>> a;
    for (int i = 0; i < 26; ++i) {
        a.push_back({frq[i], i});
    }
    sort(all(a), greater<array<int, 2>>());

    auto check = [&]() {
        for (int i = 0; i + 1 < n; ++i) {
            if (res[i] == res[i + 1]) {
                return false;
            }
        }
        for (int i = 0; i + 2 < n; ++i) {
            if (res[i] == res[i + 2]) {
                return false;
            }
        }
        return true;
    };

    auto try_random = [&]() {
        int tries = 500;
        while (tries--) {
            int beg = 0, i = 0;
            for (auto &[c, v] : a) {
                for (int j = 0; j < c; ++j) {
                    res[i] = v + 'a';
                    i += 3;
                    if (i >= n) {
                        ++beg;
                        i = beg;
                    }
                }
            }
            if (check()) return true;
            shuffle(all(a), rng);  // shuffle freq array
        }
        return false;
    };

    if (!try_random()) return void(cout << "NO\n");
    cout << "YES\n";
    cout << res << '\n';
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
