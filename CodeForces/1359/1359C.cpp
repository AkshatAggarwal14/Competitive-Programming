#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto& container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
using ld = long double;

void Solution() {
    ll h, c, t;
    cin >> h >> c >> t;
    // even - (h + c) / 2, odd - ((n + 1) * h + n * c) / (2 * n + 1), n = 0, 1 ..
    // (h + c) / 2 is the limit <- minimum we can have.
    ll l = 1, r = INF;
    --l, ++r;
    auto val = [&](ll m) -> ld { return ld(m * h + m * c - c) / ld(2 * m - 1); };
    // val >= t, T T T T F F F, as decreases
    auto can = [&](ll m) -> bool { return m * h + m * c - c >= t * (2 * m - 1); };
    while (r > l + 1) {
        ll m = (l + r) / 2;
        (can(m) ? l : r) = m;
    }
    if (l == INF) return void(cout << "2\n");
    if (abs(val(l) - t) <= abs(val(r) - t))
        cout << 2 * l - 1 << '\n';
    else
        cout << 2 * r - 1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE* in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE* out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}