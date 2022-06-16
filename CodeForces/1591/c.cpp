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
    ll n, k, num;
    cin >> n >> k;
    vector<ll> pos, neg;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        ((num > 0) ? pos : neg).push_back(abs(num));
    }
    sort(all(pos));
    sort(all(neg));
    // calculate for pos and negative seperately.
    // go reverse, handle last k, then 2nd last group of k...
    ll ans1 = 0, ans2 = 0, max1 = 0, max2 = 0;

    //? handling positives
    for (ll i = sz(pos) - 1; i >= 0; i -= k) {
        ll s = 0;
        for (ll j = i; j >= i - k && j >= 0; --j) amax(s, pos[j]);
        if (i == sz(pos) - 1) {
            ans1 += s;  // go to first group from end only once
            max1 = s;   // max element in first group from end.
        } else {
            ans1 += 2 * s;  // go to others twice
        }
    }

    //? handling negatives
    for (ll i = sz(neg) - 1; i >= 0; i -= k) {  //! O(n/k * k)
        ll s = 0;
        for (ll j = i; j >= i - k && j >= 0; --j) amax(s, neg[j]);
        if (i == sz(neg) - 1) {
            ans2 += s;  // go to first group from end only once
            max2 = s;
        } else {
            ans2 += 2 * s;  // go to others twice
        }
    }

    cout << ans1 + ans2 + min(max1, max2) << '\n';  // have to come back -> max1 or max2
}

// ----------------------------------------------------------------------------------------
void Better() {
    ll n, k, num;
    cin >> n >> k;
    vector<ll> pos, neg;
    for (ll i = 0; i < n; ++i) {
        cin >> num;
        ((num >= 0) ? pos : neg).push_back(abs(num));
    }
    sort(all(pos), greater<ll>());
    sort(all(neg), greater<ll>());
    // calculate for pos and negative seperately.
    // go reverse, handle last k, then 2nd last group of k...
    ll ans = 0;
    //? handling positives
    for (ll i = 0; i < sz(pos); i += k) ans += 2 * pos[i];  // all double
    if (sz(pos)) ans -= pos[0];                             // last once
    //? handling negatives
    for (ll i = 0; i < sz(neg); i += k) ans += 2 * neg[i];                          // all double
    if (sz(neg)) ans -= neg[0];                                                     // last once
    cout << ans + min((sz(pos) ? pos[0] : 0LL), (sz(neg) ? neg[0] : 0LL)) << '\n';  // have to come back -> max1 or max2
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
    Better();
    // Solution();
    return 0;
}
