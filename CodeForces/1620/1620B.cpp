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
    ll w, h;
    cin >> w >> h;
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        int k;
        cin >> k;
        vector<ll> v(k);
        for (int j = 0; j < k; j++) cin >> v[j];
        sort(v.begin(), v.end());
        if (i < 2)
            ans = max(ans, h * (v[k - 1] - v[0]));  // are = base * height
        else
            ans = max(ans, w * (v[k - 1] - v[0]));
    }
    cout << ans << '\n';
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