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
    ll n;
    string s;
    cin >> n >> s;
    ll cnt = count(all(s), '1');
    if (cnt % 2 == 1 || s[0] == '0' || s[n - 1] == '0') return void(cout << "NO\n");
    string a, b;
    ll k = 0;
    bool flip = false;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        } else {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n" + a + "\n" + b + "\n";
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