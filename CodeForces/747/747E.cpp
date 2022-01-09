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

// splits a std::string into vector<string> at a delimiter
vector<string> split(const string &s, const string &delims = " ") {
    vector<string> res;
    string token = "";
    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        while (delims.find(s[i]) != string::npos) {
            res.push_back(token);
            token = "";
            ++i;
        }
        token += s[i];
    }
    if (token != "") res.push_back(token);
    return res;
}

const ll MX = 3;
vector<vector<string>> ans(MX);

void Solution() {
    string s;
    cin >> s;
    vector<string> v(split(s, ","));
    vector<pair<string, ll>> st;  // use as stack
    for (ll i = sz(v) - 1; i >= 1; i -= 2) st.push_back({v[i - 1], stoll(v[i])});

    dbg(st);
    // ll n = sz(st);
    // auto dfs = [&](const auto &self, ll lvl) -> void {
    //     if (st.empty()) return;
    //     if (st.back().second == 0) {
    //         ans[lvl].push_back(st.back().first);
    //         st.pop_back();
    //     }
    //     ll cnt = st.back().second;
    //     while (cnt-- > 0) self(self, lvl + 1);
    // };
    // dfs(dfs, 0);
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