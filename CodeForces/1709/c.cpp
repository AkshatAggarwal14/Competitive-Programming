#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < int(s.length()); ++i) {
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

void test() {
    string s;
    cin >> s;
    int n = sz(s);
    int ropen = n / 2 - int(count(all(s), '(')), rclose = n / 2 - int(count(all(s), ')'));
    int t1 = ropen, t2 = rclose;
    int fopen = -1, fclose = -1;
    for (int i = 0; i < n; ++i)
        if (s[i] == '?') {
            if (t1 > 0) {
                s[i] = '(', --t1;
                fopen = i;
            } else if (t2 > 0) {
                s[i] = ')', --t2;
                if (fclose == -1) fclose = i;
            }
        }
    // as one RBS can be recovered, at this moment "s" is always valid
    if (fopen == -1 || fclose == -1) return void(cout << "YES\n");
    // swap last ( we filled with first ) we filled
    // as this is best way to swap, to get another RBS
    swap(s[fopen], s[fclose]);
    if (isValid(s))
        cout << "NO\n";
    else
        cout << "YES\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}