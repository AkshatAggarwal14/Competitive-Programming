#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll INF = LLONG_MAX;

void Solution() {
    ll n, l, r, c;
    cin >> n;
    ll L = INF, R = -1;  // make minimum L and maximum R
    // minimum cost for L, R and both together(in same index)
    ll cL = INF, cR = INF, cLR = INF;
    for (ll i = 0; i < n; ++i) {
        cin >> l >> r >> c;
        if (l < L) {
            cL = cLR = INF;
            L = l;
        }
        if (r > R) {
            cR = cLR = INF;
            R = r;
        }
        // Different index
        if (l == L) amin(cL, c);
        if (r == R) amin(cR, c);
        // if L and R for ans have same index
        if (l == L && r == R) amin(cLR, c);
        cout << min(cL + cR, cLR) << '\n';  // minimum of same index and different index
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}