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
    map<char, ll> value;
    for (ll i = 2; i <= 9; ++i) value[char(i) + '0'] = i;
    value['A'] = 1;
    value['T'] = value['J'] = value['K'] = value['Q'] = 10;

    ll n, m;
    string S;
    cin >> n >> m >> S;
    vector<ll> starIdx;
    ll otherChars = 0;
    for (ll i = 0; i < n; ++i) {
        if (S[i] == '*')
            starIdx.push_back(i);
        else
            otherChars += value[S[i]];
    }
    ll left = m - otherChars;
    ll cnt = count(all(S), '*');
    left -= cnt;
    if (left < 0 || left > 9 * cnt) return void(cout << "NO\n");
    while (!starIdx.empty()) {
        ll reduce = min(left, 9LL);

        char ch = char(reduce) + '1';
        if (ch == '1') ch = 'A';
        if (ch == char('9' + 1)) ch = 'T';
        S[starIdx.back()] = ch;

        left -= reduce;
        starIdx.pop_back();
    }
    cout << "YES\n";
    cout << S << '\n';
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