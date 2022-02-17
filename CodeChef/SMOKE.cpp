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
    int n, x, y;
    cin >> n >> x >> y;
    int cars = (n + 3) / 4, bus = 0;
    int ans = INT_MAX;
    while (cars >= 0) {
        ans = min(ans, cars * y + bus * x);
        cars -= 25;
        ++bus;
    }
    cars = (n + 99) / 100, bus = 0;
    while (cars >= 0) {
        ans = min(ans, cars * x + bus * y);
        cars--;
        bus += 25;
    }
    cout << ans << '\n';
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