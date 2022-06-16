#include "bits/stdc++.h"

using namespace std;
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

void Solution() {
    ll n, k, p = 1;
    cin >> n >> k;
    n--;
    ll ctr = 0;
    for (ll i = 0; i < 62; ++i) {
        if (p < k && p <= n) {
            ctr++;
            n -= p;
        }
        p *= 2;
    }
    cout << ctr + n / k + !!(n % k) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc;
    cin >> tc;
    while (tc--)
        Solution();
    return 0;
}