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
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    vector<ll> ans;
    for (ll k = n - 1; k >= 1; --k) {
        ll far = 0, i = k;
        while (i >= 0 && a[i] != (k + 1)) --i, ++far;
        vector<ll> b(a);
        for (i = 0; i <= k; ++i) b[i] = a[(i - far + (k + 1)) % (k + 1)];
        a = b;
        ans.push_back((k - far + 1) % (k + 1));
    }
    ans.push_back(0);
    reverse(all(ans));
    for (ll &A : ans) cout << A << ' ';
    cout << '\n';
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