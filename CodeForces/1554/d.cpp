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

/*
aaabaac -> aa wale 2*x + 1 as 2 bar equal + 1 extra a
*/
void Solution() {
    ll n;
    cin >> n;
    string s(n, 'a');
    s[n / 2] = 'b';
    if (n & 1) s[n - 1] = 'c';
    cout << s << '\n';
}

void Brute() {
    ll n;
    cin >> n;
    auto rec = [&](const auto &self, string s) -> void {
        if (sz(s) == n) {
            map<string, ll> cnt;
            for (ll i = 0; i < n; ++i) {
                string t = "";
                for (ll j = i; j < n; ++j) {
                    t += s[j];
                    ++cnt[t];
                }
            }
            for (auto &[x, y] : cnt)
                if (y % 2 == 0) return;
            cout << s << '\n';
            exit(0);
        }
        for (char ch = 'a'; ch <= 'c'; ++ch) {
            s.push_back(ch);
            self(self, s);
            s.pop_back();
        }
    };
    rec(rec, "");
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // #ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
        // Brute();
    }
    return 0;
}