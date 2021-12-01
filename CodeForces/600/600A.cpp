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
    string s;
    cin >> s;
    vector<string> ans = split(s, ";,");
    string s1 = "", s2 = "";
    auto valid = [](string str) {
        if (str.empty()) return false;
        if (str == "0") return true;
        if (str[0] == '0') return false;
        for (char &c : str)
            if (!(c >= '0' && c <= '9')) return false;
        return true;
    };
    auto add = [&](const string &what, string &to) -> void {
        if (what != "") to.append(what);
        to += ',';
    };
    for (auto &tok : ans) valid(tok) ? add(tok, s1) : add(tok, s2);
    string res1 = "", res2 = "";
    for (char &c : s1)
        if (c != '\0') res1 += c;
    for (char &c : s2)
        if (c != '\0') res2 += c;
    cout << (res1.length() == 0 ? "-" : "\"" + res1.substr(0, res1.length() - 1) + "\"") << '\n';
    cout << (res2.length() == 0 ? "-" : "\"" + res2.substr(0, res2.length() - 1) + "\"") << '\n';
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