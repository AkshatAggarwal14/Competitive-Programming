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

bool check(const vector<ll> &a) {
    vector<ll> pref(sz(a) + 1);
    partial_sum(all(a), pref.begin() + 1);
    for (ll l = 1; l < sz(pref); ++l) {
        for (ll r = l; r < sz(pref); ++r) {
            ll len = r - (l - 1);
            if (len < 2) continue;
            ll sum = pref[r] - pref[l - 1];
            if (sum % len == 0) return false;
        }
    }
    return true;
}

const ll N = 1e5;
vector<ll> p(500);

void Solution() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) cout << p[i] << ' ';
    cout << '\n';
}

int main() {
    p[0] = 2, p[1] = 1, p[2] = 4, p[3] = 3;
    for (ll i = 4; i < 500; ++i) p[i] = 4 + p[i - 4];
    assert(check(p));
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