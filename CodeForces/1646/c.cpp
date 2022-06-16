#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

/*
    Brute force on which elements from fac to consider, leftover with bits
    all elements are unique except 1 and 2, consider them in bits only

    O(2^12 log2(n))
*/

vector<ll> facs;
void Solution() {
    ll n;
    cin >> n;
    ll ans = INF;
    for (ll mask = 0; mask <= (1LL << sz(facs)); ++mask) {
        ll cur_sum = 0, bits = 0;
        for (ll i = 0; i < sz(facs); ++i)
            if (mask & (1LL << i)) cur_sum += facs[i], ++bits;
        if (cur_sum > n) continue;
        ll left_sum = n - cur_sum;
        ll cnt = bits;
        while (left_sum) {
            cnt += left_sum % 2;
            left_sum /= 2;
        }
        ans = min(ans, cnt);
    }
    if (ans == INF) return void(cout << "-1\n");
    cout << ans << '\n';
}

int main() {
    ll p = 1;
    for (ll i = 1; i <= 14; ++i) {
        p *= i;
        if (p > 2) facs.push_back(p);
    }
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}