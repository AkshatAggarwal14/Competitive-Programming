#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a ? a = std::forward<U>(b), true : false; }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b ? a = std::forward<U>(b), true : false; }

template <typename T, typename T_iterable>
vector<pair<T, ll>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, ll>> encoded;
    ll count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

/*
6 3 20
**a***
X = 20
--X, X = 19
bases = {7, 10}
B = {9, 1}
*/

void Solution() {
    ll N, K, X;
    string S;
    cin >> N >> K >> X >> S;
    X--;
    vector<pair<char, ll>> encoding = compress<char>(S);
    vector<ll> bases;
    for (auto &[x, y] : encoding)
        if (x == '*') bases.push_back(y * K + 1);  // (0, K) for each *
    vector<ll> B;
    while (!bases.empty()) {
        B.push_back(X % bases.back());
        X /= bases.back();
        bases.pop_back();
    }
    string ans = "";
    for (auto &[x, y] : encoding) {
        if (x == '*') {
            ans.append(string(B.back(), 'b'));
            B.pop_back();
        } else {
            ans.append(string(y, x));
        }
    }
    cout << ans << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}