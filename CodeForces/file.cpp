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
    ll n, q, x, y;
    cin >> n >> q;
    vector<pair<ll, ll>> Q;
    auto valid = [&](pair<ll, ll> P) {
        if (P.first == x || P.second == y) return false;          // | --
        if (abs(P.first - x) == abs(P.second - y)) return false;  // X
        return true;
    };
    for (ll i = 0; i < q; ++i) {
        cin >> x >> y;
        bool flag = true;
        for (auto &p : Q)
            if (!valid(p)) flag = false;
        if (!flag)
            cout << "NO\n";
        else {
            cout << "YES\n";
            Q.push_back({x, y});
        }
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
    Solution();
    return 0;
}