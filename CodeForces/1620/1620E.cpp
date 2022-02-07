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

const int N = 5e5 + 10;
void Solution() {
    int parent[N];
    int q;
    cin >> q;
    int n = q;
    vector<array<int, 3>> A;
    for (int i = 0; i < n; ++i) {
        int a, b, c = -1;
        cin >> a >> b;
        if (a == 2) cin >> c;
        A.push_back({a, b, c});
    }
    iota(parent, parent + N, 0LL);  // parents
    vector<int> res;
    reverse(all(A));  // reverse queries
    /*
    https://codeforces.com/blog/entry/98001?#comment-868680
    Cause when there is a type 2 query, you have to evaluate the past queries
    But if you are iterating in reverse, you can evaluate the past queries easily 
    */
    for (auto [a, b, c] : A) {
        if (a == 1) {
            res.push_back(parent[b]);
        } else {
            parent[b] = parent[c];
        }
    }
    reverse(all(res));
    for (int x : res) cout << x << ' ';
    cout << '\n';
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