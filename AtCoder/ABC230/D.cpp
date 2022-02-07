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
    using P = pair<ll, ll>;
    // sort by L and count
    ll N, D, L, R;
    vector<P> LR;
    cin >> N >> D;
    for (int i = 0; i < N; i++) cin >> L >> R, LR.emplace_back(L, R);
    sort(begin(LR), end(LR), [](P &a, P &b) { return a.second < b.second; });
    ll ans = 0, x = -(1LL << 40);
    for (auto &[l, r] : LR)
        if (x + D - 1 < l) ans++, x = r;
    cout << ans << "\n";
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