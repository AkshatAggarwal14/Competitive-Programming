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

map<ll, pair<int, int>> mp;
void init() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            mp[(1LL << i) - (1LL << j)] = {i, j};
        }
    }
}

void test() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a) cin >> x, sum += x;

    if (sum % n) return void(cout << "NO\n");
    ll avg = sum / n;

    vector<int> cnt(30, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] == avg) continue;
        // a[i] - 2^x + 2^y == sum

        if (!mp.count(a[i] - avg)) return void(cout << "NO\n");

        ++cnt[mp[a[i] - avg].first];
        --cnt[mp[a[i] - avg].second];
    }

    cout << (all_of(cnt.begin(), cnt.end(), [](int A) { return A == 0; }) ? "YES" : "NO") << '\n';
}

int32_t main() {
    init();

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
