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

const ll MAX_DEPTH = 1e6;
vector<vector<string>> ans(MAX_DEPTH + 1);

void Solution() {
    // read
    string s;
    cin >> s;
    vector<string> v(split(s, ","));
    stack<pair<string, ll>> st;
    for (ll i = sz(v) - 2; i >= 0; i -= 2)
        st.push({v[i], stoll(v[i + 1])});
    // calculate
    ll res = 0;
    auto dfs = [&](const auto &self, ll curr_depth) -> void {
        auto parent = st.top();
        st.pop();
        ans[curr_depth].push_back(parent.first);
        amax(res, curr_depth);
        while (parent.second--) {
            self(self, curr_depth + 1);
        }
    };
    // for different components.
    while (!st.empty()) dfs(dfs, 1LL);
    cout << res << '\n';
    for (ll i = 1; i <= res; ++i) {
        for (auto &x : ans[i]) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    while (tc--) {
        Solution();
    }
    return 0;
}