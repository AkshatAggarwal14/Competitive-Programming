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
const ll MOD = 1e9 + 7;  // 998244353

const ll N = ll(1e6);
array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) spf[i] = i, pr.push_back(i);
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

bool isPrime(ll n) {
    assert(n >= 0 && n <= N);
    return (spf[n] == n);
}

void test() {
    ll n;
    cin >> n;
    ll mx = 0;
    for (ll i = 0; i < sz(pr); ++i) {
        if (pr[i] > n) break;
        if (n % pr[i]) continue;
        ll temp = n, cnt = 0;
        while (temp % pr[i] == 0) {
            temp /= pr[i];
            ++cnt;
        }
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
}

int32_t main() {
    fill();
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
