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
    vector<ll> pows;
    for (ll i = 0; i <= 30; ++i) pows.push_back(1LL << i);
    vector<ll> A(3);
    for (auto &i : A) cin >> i;
    sort(all(A));
    bool ans = false;
    auto check = [&](ll a, ll b, ll c, ll m) {
        a = m - a, b = m - b, c = m - c;
        if ((b & a) == 0 and (a & c) == 0 and (b & c) == 0) return true;
        return false;
    };
    ll sum = accumulate(all(A), 0LL);
    for (ll i = 0; i <= 30; ++i) {
        ll curr = sum + (pows[i] - 1);
        if (curr % 3 == 0) {
            if (check(A[0], A[1], A[2], curr / 3)) ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
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
