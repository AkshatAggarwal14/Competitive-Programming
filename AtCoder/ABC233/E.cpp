#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void Solution() {
    string s;
    cin >> s;
    ll n = sz(s);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) a[i] = s[i] - '0';
    vector<ll> pref(n, 0);
    partial_sum(all(a), pref.begin());
    reverse(all(pref));
    string ans = "";
    dbg(pref);
    ll carry = 0;
    for (ll i = 0; i < n; ++i) {
        ll curr = (pref[i] + carry);
        ans += (char(curr % 10) + '0');
        carry = curr / 10;
    }
    reverse(all(ans));
    ans = to_string(carry) + ans;
    reverse(all(ans));
    while (!ans.empty() && ans.back() == '0') ans.pop_back();
    reverse(all(ans));
    cout << ans;
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