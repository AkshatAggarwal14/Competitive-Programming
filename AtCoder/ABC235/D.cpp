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

//! DFS doesnt work because the vis can be visited in smaller time from some other node!
void BFS() {
    map<ll, ll> operations;
    ll a, n;
    cin >> a >> n;
    queue<ll> bfs;
    bfs.push(1);
    operations[1] = 0;
    while (!bfs.empty()) {
        ll node = bfs.front();
        bfs.pop();
        ll n1 = node * a;
        if (!operations.count(n1) && sz(to_string(n1)) <= sz(to_string(n)))
            bfs.push(n1), operations[n1] = operations[node] + 1;
        string S = to_string(node);
        if (S.back() != '0' && sz(S) >= 2) {
            rotate(S.begin(), S.begin() + (sz(S) - 1), S.end());
            ll n2 = stoll(S);
            if (!operations.count(n2) && sz(to_string(n2)) <= sz(to_string(n)))
                bfs.push(n2), operations[n2] = operations[node] + 1;
        }
    }
    if (!operations.count(n)) return void(cout << "-1\n");
    cout << operations[n] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        BFS();
    }
    return 0;
}