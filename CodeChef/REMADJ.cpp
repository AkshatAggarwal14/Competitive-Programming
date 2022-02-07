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
void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ll SUM = accumulate(all(a), 0LL);
    if (SUM < 0) {
        SUM = -SUM;
        for (ll &i : a) i = -i;
    }
    // sum of array remains constant
    // calculate minimum number of operations required to make all elements of array equal if in one operation we can replace two adjacent elements with there sum
    // so, each element must be sum/x for some divisor x.
    vector<ll> choices;
    if (SUM == 0) {
        choices.push_back(0);
    } else {
        for (ll i = 1; i * i <= SUM; i++) {
            if (SUM % i == 0) {
                choices.push_back(i);
                if (i != SUM / i) choices.push_back(SUM / i);
            }
        }
    }
    ll best = n - 1;  // atmost
    for (auto &potential_ans : choices) {
        for (ll _ = 0; _ < 2; ++_) {
            vector<pair<ll, ll>> Rs;
            ll last = -1, sum = -1, ans = 0;
            for (ll i = 0; i < n;) {
                last = i;
                sum = a[i];
                ++i;
                while (i < n && sum != potential_ans) {
                    sum += a[i];
                    i++;
                }
                if (_ == 0) {
                    while (i < n && a[i] == 0) {  //! fuck zeroes
                        i++;
                    }
                }
                Rs.push_back({last, i - 1});
                ans += (i - 1) - last;
            }
            // validate
            bool valid = true;
            for (auto &[x, y] : Rs) {
                ll S = 0;
                for (ll i = x; i <= y; ++i) {
                    S += a[i];
                }
                if (S != potential_ans) valid = false;
            }
            // check only if validated
            if (valid && !Rs.empty() && Rs.back().second == n - 1)
                amin(best, ans);
            if (best == 0) break;
        }
    }
    reverse(all(a));
    for (auto &potential_ans : choices) {
        for (ll _ = 0; _ < 2; ++_) {
            vector<pair<ll, ll>> Rs;
            ll last = -1, sum = -1, ans = 0;
            for (ll i = 0; i < n;) {
                last = i;
                sum = a[i];
                ++i;
                while (i < n && sum != potential_ans) {
                    sum += a[i];
                    i++;
                }
                if (_ == 0) {
                    while (i < n && a[i] == 0) {  //! fuck zeroes
                        i++;
                    }
                }
                Rs.push_back({last, i - 1});
                ans += (i - 1) - last;
            }
            // validate
            bool valid = true;
            for (auto &[x, y] : Rs) {
                ll S = 0;
                for (ll i = x; i <= y; ++i) {
                    S += a[i];
                }
                if (S != potential_ans) valid = false;
            }
            // check only if validated
            if (valid && !Rs.empty() && Rs.back().second == n - 1)
                amin(best, ans);
            if (best == 0) break;
        }
    }
    assert(best >= 0 && best <= n - 1);
    cout << best << '\n';
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