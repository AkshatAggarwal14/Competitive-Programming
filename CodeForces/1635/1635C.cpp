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
    if (is_sorted(all(a))) return void(cout << "0\n");
    if (a[n - 1] < a[n - 2] || a[n - 1] < 0) return void(cout << "-1\n");
    vector<pair<pair<ll, ll>, ll>> ans;
    for (ll i = n - 3; i >= 0; --i) {
        a[i] = a[n - 2] - a[n - 1];
        ans.push_back({{i + 1, n - 1}, n});
    }
    if (is_sorted(all(a))) {
        cout << sz(ans) << '\n';
        for (auto &it : ans) cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
    } else {
        cout << "-1\n";
    }
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