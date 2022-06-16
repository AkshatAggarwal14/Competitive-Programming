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

void Math() {
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll mini = *min_element(all(a)), maxi = *max_element(all(a));
    // this is done as if lights at 2,5 where l=5 thus -2 has to be added so ans=2 as from 0
    a.push_back(-mini);
    // it was done to create mirror image of min element with 0 as mirror
    a.push_back(2 * l - maxi);   // this is done to create mirror image of max element with "l" as mirror
    vector<ll> diff(sz(a) - 1);  // diff b/w consecutive
    sort(all(a), greater<ll>());
    for (ll i = 0; i < sz(diff); ++i) diff[i] = a[i] - a[i + 1];
    double ans = double(*max_element(all(diff))) / 2;
    cout << ans << '\n';
}

template <bool b>
auto binsearch(auto l, auto r, const auto &pred) {
    --l, ++r;
    for (decltype(l) m; m = midpoint(l, r), r > l + 1;) (pred(m) ? l : r) = m;
    return (b ? l : r);
}
// returns first i in [l, r], p(i) false, and if none found, returns r + 1
auto find_first_false(auto l, auto r, const auto &p) { return binsearch<false>(l, r, p); }
// returns last i in [l, r], p(i) true, and if none found, returns l - 1
auto find_last_true(auto l, auto r, const auto &p) { return binsearch<true>(l, r, p); }

const ll EXP = 1e9;  //! multiply everything by 1e9, to remove decimals
void BinarySearch() {
    ll n, l;
    cin >> n >> l;
    l *= EXP;
    vector<ll> a(n);
    for (ll &x : a) cin >> x, x *= EXP;
    // limits
    a.push_back(-*min_element(all(a)));
    a.push_back(2 * l - *max_element(all(a)));
    sort(all(a));
    vector<ll> diff(sz(a) - 1);
    for (ll i = 0; i < sz(diff); ++i) diff[i] = a[i + 1] - a[i];
    ll ans = find_first_false(0LL, EXP * EXP, [&](ll d) {
        for (ll i = 0; i < sz(diff); ++i) {
            if (2 * d < diff[i]) return true;
        }
        return false;
    });
    cout << double(ans) / EXP << '\n';
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
    Math();
    // BinarySearch();
    return 0;
}
