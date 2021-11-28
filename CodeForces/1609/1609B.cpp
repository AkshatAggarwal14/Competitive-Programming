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

void Solution() {
    ll n, q, pos = 0;
    string s;
    cin >> n >> q >> s;
    map<string, ll> idx;
    for (char a = 'a'; a <= 'c'; ++a) {
        string ss = "";
        ss += a;
        for (char b = 'a'; b <= 'c'; ++b) {
            string s1 = ss;
            s1 += b;
            for (char c = 'a'; c <= 'c'; ++c) {
                string s2 = s1;
                s2 += c;
                idx[s2] = pos++;
            }
        }
    }
    map<ll, set<ll>> mp;
    for (ll i = 2; i < n; ++i) {
        string t = "";
        t += s[i - 2], t += s[i - 1], t += s[i];
        mp[idx[t]].insert(i - 1);  // middle char is idx
    }
    while (q--) {
        ll I;
        char C;
        cin >> I >> C;
        I--;
        vector<ll> valid = {I - 1, I, I + 1};
        for (ll &id : valid) {
            if (id >= 1 && id < n - 1) {
                string temp = "";
                temp += s[id - 1], temp += s[id], temp += s[id + 1];
                mp[idx[temp]].erase(id);
            }
        }
        s[I] = C;
        for (ll &id : valid) {
            if (id >= 1 && id < n - 1) {
                string temp = "";
                temp += s[id - 1], temp += s[id], temp += s[id + 1];
                mp[idx[temp]].insert(id);
            }
        }
        cout << sz(mp[idx["abc"]]) << '\n';
    }
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