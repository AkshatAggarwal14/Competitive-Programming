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

struct node {
    ll x, value, index;
};

void Solution() {
    ll n, m;
    cin >> n >> m;
    vector<node> a(m);
    for (ll i = 1; auto &[x, wt, id] : a) cin >> x >> wt, id = i++;
    sort(all(a), [](const node &A, const node &B) { return A.value < B.value; });
    while (sz(a) > 2 * n) a.pop_back();  // keep smallest values
    sort(all(a), [](const node &A, const node &B) { return A.x < B.x; });
    vector<ll> ids;
    ll sum = 0;
    for (ll i = 0; i < 2 * n; ++i) {
        sum += a[i].value;
        ids.push_back(a[i].index);
    }
    cout << sum << '\n';
    for (ll i = 0; i < n; ++i)
        cout << ids[i] << ' ' << ids[2 * n - 1 - i] << '\n';
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