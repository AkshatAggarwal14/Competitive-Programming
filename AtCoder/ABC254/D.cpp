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
const ll N = 2e5;

array<ll, N + 1> spf;
vector<ll> pr;
void fill() {
    for (ll i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            pr.push_back(i);
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

// Returns a vector containing all the prime factors of n (25 --> 5, 5)
vector<ll> prime_factorisation(ll n) {
    vector<ll> ans;
    while (n != 1) {
        ll i = spf[n];
        ll j = 0;
        while (n % i == 0) {
            n /= i;
            j++;
        }
        if (j & 1) ans.push_back(i);
    }
    return ans;
}

void test() {
    fill();

    ll n;
    cin >> n;
    vector<ll> vis(n + 1, false);
    vector<vector<ll>> k(n + 1);
    map<vector<ll>, ll> freq;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            k[i] = prime_factorisation(i);
            vis[i] = true;
        }
        ++freq[k[i]];
    }
    ll sum = 0;
    for (auto i : freq) sum += ((i.second - 1) * i.second) / 2;
    cout << n + 2 * sum << '\n';
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
