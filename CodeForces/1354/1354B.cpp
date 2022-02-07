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

// make pair with count of contiguous..
vector<pair<char, ll>> compress(const string &t) {
    if (t.empty()) return {};
    vector<pair<char, ll>> res;
    ll cnt = 0;
    char last = t[0];
    for (ll i = 0; i < sz(t); ++i) {
        if (t[i] == last) {
            cnt++;
        } else {
            res.push_back({last, cnt});
            last = t[i], cnt = 1;
        }
    }
    if (cnt) res.push_back({last, cnt});
    return res;
}

void Solution() {
    string s;
    cin >> s;
    vector<pair<char, ll>> c = compress(s);
    ll ans = LLONG_MAX;
    for (ll i = 0; i < sz(c) - 2; ++i) {
        set<char> st;
        for (ll j = i; j < i + 3; ++j) st.insert(c[j].first);
        if (sz(st) == 3) amin(ans, 2 + c[i + 1].second);  // abbbbbc
    }
    cout << (ans == LLONG_MAX ? 0 : ans) << '\n';
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