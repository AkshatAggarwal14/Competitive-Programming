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

void Solution() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    iota(all(p), 1);
    reverse(all(p));
    ll ctr = 0;
    do {
        bool flag = true;
        for (ll i = 2; i < n; ++i) {
            if (p[i] == p[i - 1] + p[i - 2]) {
                flag = false;
            }
        }
        if (flag) {
            for (ll &P : p) cout << P << ' ';
            cout << '\n';
            ctr++;
            if (ctr == n) return;
        }
    } while (prev_permutation(all(p)));
}

int main() {
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