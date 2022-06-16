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

void Solution() {
    // first place all ( then place all ).
    ll n;
    string s;
    cin >> n >> s;
    if (n & 1) return void(cout << ":(\n");
    ll open = n / 2 - count(all(s), '(');
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '?' && open-- > 0) {
            s[i] = '(';
        } else if (s[i] == '?') {
            s[i] = ')';
        }
    }
    auto check = [&](const string &S) -> bool {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < ll(S.length()); ++i) {
            if (st.empty()) {
                return false;  // stack becomes empty
            } else {
                if (st.top() == '(' && S[i] == ')') {
                    st.pop();
                } else {
                    st.push(S[i]);
                }
            }
        }
        return st.empty();
    };
    cout << (check(s) ? s : ":(") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}