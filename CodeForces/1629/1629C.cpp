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
    vector<ll> a(n), cnt(n + 1);
    for (auto &A : a) cin >> A, ++cnt[A];
    set<ll> st;
    for (ll i = 0; i <= n; i++)
        if (!cnt[i]) st.insert(i);
    if (st.empty()) {
        cout << "1\n";
        cout << n + 1 << '\n';
        return;
    }
    vector<ll> ans;
    vector<bool> vis(n + 1, false);

    for (ll i = 0; i < n;) {
        fill(all(vis), false);
        ll x = *st.begin(), cc = 0, j = i;
        for (; j < n; j++) {
            ll elem = a[j];
            cnt[elem]--;
            if (cnt[elem] == 0) st.insert(elem);
            if (a[j] < x && !vis[a[j]]) vis[a[j]] = true, cc++;
            if (cc == x) {
                ans.push_back(x);
                break;
            }
        }
        i = j + 1;
    }
    cout << sz(ans) << '\n';
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
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