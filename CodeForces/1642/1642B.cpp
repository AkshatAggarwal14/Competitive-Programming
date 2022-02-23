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

// until k = number of distinct elements we can keep the ans = number of distinct elements, after that as we seperate 1, ans increases by 1 everytime

void Solution() {
    map<ll, ll> cnt;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A, ++cnt[A];
    vector<ll> siz;
    for (auto &[x, y] : cnt) siz.push_back(y);
    sort(all(siz));
    ll cc = sz(siz);
    vector<ll> ans(n);
    for (ll i = 0; i < cc; ++i) ans[i] = cc;
    for (ll i = cc; i < n; ++i) ans[i] = ans[i - 1] + 1;
    for (ll &x : ans) cout << x << ' ';
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