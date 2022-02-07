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
    cin >> n >> s;
    if (n & 1) return void(cout << "NO\n");
    vector<ll> cnt(26, 0);
    for (ll i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
    for (ll i = 0; i < 26; ++i)
        if (cnt[i] > n / 2) return void(cout << "NO\n");
    cout << "YES\n";
    sort(all(s));
    string res = "";
    int l = 0, r = n - 1;
    for (int _ = 0; _ < n / 2; _++) {
        res += s[r--];
        res += s[l++];
    }
    cout << res << '\n';
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