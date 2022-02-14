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
    ll n;
    cin >> n;
    vector<ll> a(n + 1), pos(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    set<ll> st;
    for (ll i = 1; i <= n; i++) st.insert(i);

    vector<bool> mark(n + 1, false);
    ll ans = 0;
    for (ll i = n; i >= 1; i--) {
        if (st.lower_bound(i) == st.end()) continue;
        if (*st.lower_bound(i) != i) continue;
        if (sz(st) == i) ans++;
        ll j = pos[i];
        while (j <= n && !mark[j]) {
            st.erase(a[j]), mark[j] = true;
            j++;
        }
    }
    cout << ans << "\n";
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