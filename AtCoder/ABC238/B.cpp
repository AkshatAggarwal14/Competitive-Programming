#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

void Solution() {
    ll n, num, sum = 0;
    cin >> n;
    vector<ll> cuts = {0};
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        sum += num;
        sum %= 360;
        cuts.push_back(sum);
    }
    cuts.push_back(360);
    sort(all(cuts));
    cuts.resize(unique(all(cuts)) - cuts.begin());
    dbg(cuts);
    ll diff = 0;
    for (ll i = 0; i < sz(cuts) - 1; ++i) amax(diff, (cuts[i + 1] - cuts[i]));
    cout << diff << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}