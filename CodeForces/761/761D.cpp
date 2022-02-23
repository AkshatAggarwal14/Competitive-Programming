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

#define ff first
#define ss second
using node = pair<ll, pair<ll, ll>>;
void Solution() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<node> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i].ff;
    for (ll i = 0; i < n; ++i) cin >> a[i].ss.ff, a[i].ss.ss = i;
    sort(all(a), [](const node &A, const node &B) {
        return A.ss.ff < B.ss.ff;
    });
    ll prev = -INF;
    vector<pair<ll, ll>> b(n);
    for (ll i = 0; i < n; ++i) b[i].ss = a[i].ss.ss;
    for (ll i = 0; i < n; ++i) {
        // min C in range, [l - a[i], r - a[i]] such that C > prev as c[i] = b[i] - a[i]
        // C = max(l - a[i].ff, prev + 1)
        ll C = max(l - a[i].ff, prev + 1);
        b[i].ff = C + a[i].ff;
        if (b[i].ff > r) return void(cout << "-1\n");
        prev = C;
    }
    sort(all(b), [](const pair<ll, ll> &A, const pair<ll, ll> &B) {
        return A.ss < B.ss;
    });
    for (auto &[x, y] : b) cout << x << ' ';
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
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}