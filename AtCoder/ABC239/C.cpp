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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll d_sq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    /*
    let:
    q = sqrt((x2-x1)^2 + (y2-y1)^2)
    x3 = (x1+x2)/2
    y3 = (y1+y2)/2

    first circle:
    x = x3 + sqrt(r^2-(q/2)^2)*(y1-y2)/q
    y = y3 + sqrt(r^2-(q/2)^2)*(x2-x1)/q

    Second Circle:
    x = x3 - sqrt(r^2-(q/2)^2)*(y1-y2)/q
    y = y3 - sqrt(r^2-(q/2)^2)*(x2-x1)/q
    */
    if (d_sq > 20) return void(cout << "No\n");

    bool c1 = ((20 - d_sq) * (y1 - y2) * (y1 - y2)) % (d_sq) == 0;
    ll val1 = ((20 - d_sq) * (y1 - y2) * (y1 - y2)) / (d_sq);
    ll sq_val1 = ll(sqrt(val1));
    bool c2 = (sq_val1 * sq_val1 == val1);

    bool c3 = ((20 - d_sq) * (x2 - x1) * (x2 - x1)) % (d_sq) == 0;
    ll val2 = ((20 - d_sq) * (x2 - x1) * (x2 - x1)) / (d_sq);
    ll sq_val2 = ll(sqrt(val2));
    bool c4 = (sq_val2 * sq_val2 == val2);

    bool c5 = ((val1 + x1 + x2) % 2 == 0) && ((val2 + y1 + y2) % 2 == 0);
    bool c6 = ((x1 + x2 - val1) % 2 == 0) && ((y1 + y2 - val2) % 2 == 0);

    if (c1 && c2 && c3 && c4 && (c5 || c6)) return void(cout << "Yes\n");
    cout << "No\n";
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