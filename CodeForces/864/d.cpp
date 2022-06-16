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
    ll n = 0;
    cin >> n;
    vector<ll> a(n + 1), mark(n + 1, 0), freq(n + 1, 0);
    for (ll i = 1; i <= n; ++i) cin >> a[i], freq[a[i]]++;
    vector<ll> ans(a);
    ll cnt = 0;
    for (auto it : freq)
        if (it > 0) cnt += it - 1;
    set<ll> not_present;
    for (ll i = 1; i <= n; ++i)
        if (freq[i] == 0) not_present.insert(i);
    for (ll i = 1; i <= n; ++i) {
        if (freq[ans[i]] == 1) {
            mark[ans[i]] = 1;
            continue;
        }
        if (mark[ans[i]] || *not_present.begin() < ans[i]) {
            freq[ans[i]]--;
            ans[i] = *not_present.begin();
            mark[*not_present.begin()] = 1;
            not_present.erase(not_present.begin());
        } else
            mark[ans[i]] = 1;
        dbg(mark, freq);
    }
    cout << cnt << '\n';
    for (ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
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