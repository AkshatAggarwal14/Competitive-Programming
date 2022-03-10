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

// top right corner for first, bottom left for n

void Solution() {
    set<pair<ll, ll>> st;
    ll n;
    cin >> n;
    st.emplace(0, -1);
    st.emplace(-1, 0);
    st.emplace(-1, -1);
    for (ll i = 0; i < n; ++i) {
        st.emplace(i, i);
        st.emplace(i, i + 1);
        st.emplace(i + 1, i + 1);
        st.emplace(i + 1, i);
    }
    cout << sz(st) << '\n';
    for (auto &[x, y] : st) cout << x << ' ' << y << '\n';
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