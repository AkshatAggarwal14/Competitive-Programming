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

vector<ll> fact(20, 1);
void Solution() {
    const auto calculate = [&](vector<ll> C) -> ll {
        ll res = 0;
        ll num_before_fact = accumulate(all(C), 0LL);
        ll den = 1;
        for (ll d = 0; d <= 9; ++d) den *= fact[C[d]];
        // handle 1st digit seperately
        for (ll i = 1; i < 10; ++i) {
            if (!C[i]) continue;
            // fix 1st digit as i
            ll numerator = fact[num_before_fact - 1];  // fixed
            ll denominator = (den / fact[C[i]]) * fact[C[i] - 1];
            res += numerator / denominator;
        }
        return res;
    };

    string s;
    cin >> s;
    vector<ll> cnt(10, 0);
    for (char &c : s) ++cnt[c - '0'];
    ll total = 0;
    auto backtrack = [&](const auto self, ll digit, vector<ll> C) {
        if (digit == 10) {  // done for all digits 0...9
            dbg(C);
            total += calculate(C);
            return;
        }
        if (!cnt[digit]) {
            C.push_back(0);
            self(self, digit + 1, C);
            C.pop_back();
        } else {
            for (ll i = 1; i <= cnt[digit]; ++i) {
                C.push_back(i);  // for all 1, 2... cnt[dig]
                self(self, digit + 1, C);
                C.pop_back();
            }
        }
    };
    backtrack(backtrack, 0LL, {});
    cout << total << '\n';
}

int main() {
    for (ll i = 1; i < 20; ++i) fact[i] = fact[i - 1] * i;
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