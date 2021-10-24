#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define sz(x) ((ll)(x).size())
const double eps = 1e-12;
const double PI = acos(-1);

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if ((st.top() == '(' && s[i] == ')') or (st.top() == '{' && s[i] == '}') or (st.top() == '[' && s[i] == ']')) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    if (st.empty()) return true;
    return false;
}

void Solution() {
    ll n;
    string s;
    cin >> n >> s;
    ll cnt = count(s.begin(), s.end(), '1');
    if (cnt % 2 == 1 || s[0] == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }
    string a, b;
    ll k = 0;
    bool flip = false;
    fo(i, n) {
        if (s[i] == '1') {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        } else {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n" + a + "\n" + b + "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef NCR
    init();
#endif
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        Solution();
    }
    return 0;
}