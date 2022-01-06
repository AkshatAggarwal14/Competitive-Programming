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
    ll n, m;
    string S;
    cin >> n >> m >> S;
    map<char, ll> value;
    for (ll i = 2; i <= 9; ++i) value[char(i) + '0'] = i;
    value['A'] = 1;
    value['T'] = 10;
    value['J'] = value['K'] = value['Q'] = 10;
    auto dfs = [&](const auto &self, string s) -> void {
        ll val = 0;
        bool flag = true;
        for (ll i = 0; i < n; ++i) {
            if (s[i] == '*')
                flag = false;
            else
                val += value[s[i]];
        }
        if (flag && val == m) {
            cout << "YES\n", cout << s << '\n';
            exit(0);
        }
        for (ll i = 0; i < n; ++i) {
            if (s[i] == '*') {
                for (char j = '2'; j <= '9'; ++j) {
                    s[i] = j;
                    self(self, s);
                }
                s[i] = 'A';
                self(self, s);
                s[i] = 'T';
                self(self, s);
                s[i] = 'J';  // as J, K, Q have same value
                self(self, s);
            }
        }
    };
    dfs(dfs, S);
    cout << "NO\n";
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