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
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    for (ll i = 0, x; i < n; ++i) cin >> x, mp[x]++;
    vector<ll> b(m);
    for (ll &B : b) cin >> B;
    for (ll i = 0; i < m; ++i) {
        if (!mp.count(b[i]))
            return void(cout << "No\n");
        else {
            --mp[b[i]];
            if (mp[b[i]] == 0) mp.erase(b[i]);
        }
    }
    cout << "Yes\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}