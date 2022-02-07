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

// a permutation is a group of cycles
void Solution() {
    int n;
    cin >> n;
    vector<int> ans(n, -1);
    int prev = -1, nxt = -1;
    auto ask = [&](const int &idx) -> int {
        cout << "? " << idx + 1 << endl;
        int res;
        cin >> res;
        if (res == 0) exit(0);
        return res - 1;
    };

    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1) continue;  // already visited
        prev = ask(i);
        while (ans[prev] == -1) {  // until ans[prev] is not set
            nxt = ask(i);          // ask next
            ans[prev] = nxt;       // set nxt
            prev = nxt;
        }
    }

    cout << "! ";
    for (auto &a : ans) cout << a + 1 << ' ';
    cout << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}