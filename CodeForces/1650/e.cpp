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
    int n, d;
    cin >> n >> d;

    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
        t[i] = a[i] - ((i == 0) ? 0 : (a[i - 1] + 1));
    }
    int j = int(distance(t.begin(), min_element(t.begin(), t.end())));
    int ans = 0;
    for (auto x : {j - 1, j}) {  // indexes dealing with min distance
        if (x < 0) continue;
        int last = -1, mx = 0, mn = d;
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            mx = max(mx, a[i] - last - 1);
            mn = min(mn, a[i] - last - 1);
            last = a[i];
        }
        ans = max(ans, min(mn, max(d - 2 - last, (mx - 1) / 2)));
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