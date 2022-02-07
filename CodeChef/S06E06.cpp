#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

void Solution() {
    string n;
    ll k;
    cin >> n >> k;
    multiset<char> st(all(n));
    while (k--) {
        char f = *st.begin();
        if (f == '9') break;
        st.erase(st.lower_bound(f));
        f++;
        st.insert(f);
    }
    ll p = 1;
    for (auto &c : st) p *= (c - '0');
    cout << p << '\n';
}

// clang-format off
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc; cin >> tc; while (tc--)
    Solution();
    return 0;
}