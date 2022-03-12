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

// how to handle overflow in between tests
// use stack and count Rs or Ls with Us
void test() {
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    stack<char> st;
    for (ll i = 0; i < n; ++i) {
        if (st.empty()) {
            st.push(s[i]);
        } else if (st.top() != 'U' && s[i] == 'U') {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    string moves = "";
    while (!st.empty()) moves += st.top(), st.pop();
    reverse(all(moves));
    dbg(moves);
    for (ll i = 0; i < sz(moves); ++i) {
        if (moves[i] == 'U') {
            x /= 2;
        } else if (moves[i] == 'L') {
            x *= 2;
        } else {
            x *= 2;
            x = x + 1;
        }
    }
    cout << x << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
