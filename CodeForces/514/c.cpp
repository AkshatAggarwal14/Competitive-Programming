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
const ll N = 6e5 + 5;
const ll MOD = 1e14 + 9;  // 998244353
/**
 * As there are (26n)^2 = 6e13 -> take prime larger than this as collisions ~ 1/p
 */
const ll P = 4;
ll power[N];

void test() {
    ll _n, m;
    cin >> _n >> m;
    set<ll> hashes;
    auto getHash = [&](string s) {
        ll hash = 0, n = int(s.size());
        for (ll i = 0; i < n; ++i) {
            hash += power[i] * (s[i] - 'a' + 1);
            hash %= MOD;
        }
        return hash;
    };
    for (ll i = 0; i < _n; ++i) {
        string s;
        cin >> s;
        hashes.insert(getHash(s));
    }
    while (m--) {
        string s;
        cin >> s;
        bool flag = false;
        ll hash = getHash(s), n = int(s.size());
        for (ll i = 0; i < n; ++i) {
            for (char c = 'a'; c <= 'c'; ++c) {
                if (c == s[i]) continue;
                ll nhash = hash + (int(c) - int(s[i])) * power[i];
                nhash = (nhash % MOD + MOD) % MOD;
                if (hashes.contains(nhash)) {
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}

int32_t main() {
    power[0] = 1;
    for (ll i = 1; i < N; ++i)
        power[i] = (P * power[i - 1]) % MOD;

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