#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> int { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n), cnt(n + 1, 0);
    for (ll &x : a) cin >> x, ++cnt[x];
    priority_queue<ll> q;
    vector<ll> ans(n + 1, -1);
    ll offset = 0;
    for (ll i = 0; i <= n; ++i) {
        ans[i] = offset + cnt[i];
        if (cnt[i] == 0) {            // if current element not present
            if (q.empty()) break;     // -1 on this and afterwards
            offset += (i - q.top());  // need larger element where element not present
            q.pop();
        }
        while (cnt[i] > 1) q.push(i), --cnt[i];  // all occurences except previous 1 needed
    }
    for (ll &x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}