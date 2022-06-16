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

void Solution() {
    ll q;
    cin >> q;
    string cmd, s;
    vector<string> curr_path;
    while (q--) {
        cin >> cmd;
        if (cmd == "pwd"s) {
            cout << "/"s;
            for (auto &x : curr_path) cout << x << '/';
            cout << '\n';
        } else {
            cin >> s;
            vector<string> tokens = split(s, "/"s);
            if (tokens[0] == ""s) {
                curr_path.clear();
                for (ll i = 1; i < sz(tokens); ++i) {
                    if (tokens[i] == ".."s)
                        curr_path.pop_back();
                    else
                        curr_path.push_back(tokens[i]);
                }
            } else {
                for (ll i = 0; i < sz(tokens); ++i) {
                    if (tokens[i] == ".."s)
                        curr_path.pop_back();
                    else
                        curr_path.push_back(tokens[i]);
                }
            }
        }
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