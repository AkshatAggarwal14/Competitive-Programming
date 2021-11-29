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
                idx[s2] = pos++;  // generate all 3 letter combo and assign index
            }
        }
    }
    map<ll, set<ll>> mp;  // to store indices of a particular 3 letter substring
    for (ll i = 2; i < n; ++i) {
        string t = "";
        t += s[i - 2], t += s[i - 1], t += s[i];
        mp[idx[t]].insert(i - 1);  // middle char of 3 letter string is its index
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
                mp[idx[temp]].erase(id);  // erase the index from curr 3 strings
            }
        }
        s[I] = C;
        for (ll &id : valid) {
            if (id >= 1 && id < n - 1) {
                string temp = "";
                temp += s[id - 1], temp += s[id], temp += s[id + 1];
                mp[idx[temp]].insert(id);  // store index of modified strings
            }
        }
        cout << sz(mp[idx["abc"]]) << '\n';  // abc can be changes to acc etc, so just need its count as output
    }
}

// ----------------------------------------------------------------------------
// only need count of "abc"s, others were unnecessary
void Better() {
    ll n, q, abc = 0, idx;
    string s;
    char ch;
    cin >> n >> q >> s;
    for (ll i = 2; i < n; i++)
        if (s.substr(i - 2, 3) == "abc") ++abc;
    for (ll i = 0; i < q; i++) {
        cin >> idx >> ch;
        idx--;
        // remove the 3 abc's
        for (ll l = max(0LL, idx - 2), r = l + 2; r < min(n, idx + 3); l++, r++)
            if (s.substr(l, 3) == "abc") --abc;
        s[idx] = ch;
        // add the 3 abc's if present
        for (ll l = max(0LL, idx - 2), r = l + 2; r < min(n, idx + 3); l++, r++)
            if (s.substr(l, 3) == "abc") ++abc;
        cout << abc << "\n";
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
    Better();
    return 0;
}