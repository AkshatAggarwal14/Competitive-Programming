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

string build(const char &c1, const char &c2, const ll &n) {
    string res = "";
    for (ll i = 0; i < n; ++i) res += ((i & 1) ? c2 : c1);
    return res;
}

// make pair with count of contiguous..
vector<pair<char, ll>> compress(const string &t) {
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
    string s, t;
    cin >> s >> t;
    string ans = "";
    vector<pair<char, ll>> C = compress(s);
    for (ll i = 0; i < sz(C); ++i) {
        if (C[i].first == '?') {
            if (i > 0 && C[i - 1].first == t[0]) {
                ans.append(build(t[1], t[0], C[i].second));
            } else {
                ans.append(build(t[0], t[1], C[i].second));
            }
        } else {
            ans.append(string(C[i].second, C[i].first));
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < sz(ans) - 1; ++i) cnt += (ans.substr(i, 2) == t);
    cout << cnt << '\n';
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
    // ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}