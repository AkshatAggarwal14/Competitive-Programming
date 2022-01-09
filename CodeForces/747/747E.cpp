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
    vector<pair<string, ll>> a;
    for (ll i = 0; i < sz(v) - 1; i += 2)
        a.push_back({v[i], stoll(v[i + 1])});
    // calculate
    ll mx_depth = 0, n = sz(a), pos = 0;
    vector<ll> depth(n, -1);  // use as visited

    auto dfs = [&](const auto &self, ll parent) {
        if (pos >= n) return;
        while (a[parent].second--) {
            ++pos;
            depth[pos] = depth[parent] + 1;
            self(self, pos);  // go deeper (dfs), then come back when a[idx].second == 0
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (depth[i] == -1) {
            depth[i] = 1;
            dfs(dfs, i);
            ++pos;  // covers one tree thingy in one go, then move to next index
        }
        amax(mx_depth, depth[i]);
        ans[depth[i]].push_back(a[i].first);
    }

    // print
    cout << mx_depth << '\n';
    for (ll i = 1; i <= mx_depth; ++i) {
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
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}