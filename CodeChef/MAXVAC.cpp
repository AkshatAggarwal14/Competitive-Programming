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

void Solution() {
    ll n, x;
    string s;
    cin >> n >> x >> s;
    auto C = compress<char>(s);
    ll ans = 0;
    for (auto &[X, y] : C)
        if (X == '0') ans += y / x;
    ll mx = ans;
    for (ll i = 0; i < sz(C) - 1; ++i) {
        ll t = ans;
        if (i < sz(C) - 2 && C[i].first == '0' && C[i + 1].first == '1' && C[i + 2].first == '0' && C[i + 1].second == 1) {
            // 0000010000 case
            t -= (C[i].second / x + C[i + 2].second / x);
            t += (C[i].second + C[i + 2].second + 1) / x;
        } else if (C[i].first == '0' && C[i + 1].first == '1') {
            t -= (C[i].second / x);
            t += (C[i].second + 1) / x;
        } else if (C[i].first == '1' && C[i + 1].first == '0') {
            t -= (C[i + 1].second / x);
            t += (C[i + 1].second + 1) / x;
        }
        amax(mx, t);
    }
    cout << mx << '\n';
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