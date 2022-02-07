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
    string s;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> like, dislike;
    for (ll &A : a) cin >> A;
    cin >> s;
    for (ll i = 0; i < n; i++) ((s[i] == '1' ? like : dislike)).push_back({a[i], i});
    sort(all(like));
    sort(all(dislike));
    vector<ll> ans(n);
    ll num = 1;
    for (auto &[x, y] : dislike) ans[y] = num++;
    for (auto &[x, y] : like) ans[y] = num++;
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