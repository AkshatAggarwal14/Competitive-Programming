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
    auto closest = [](const vector<ll> &x, ll target) -> pair<ll, ll> {
        ll lo = 0, hi = sz(x) - 1;
        while (hi - lo > 1) {
            ll mid = ((lo + hi) / 2);
            if (x[mid] < target) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return {x[lo], x[hi]};
    };
    auto val = [&](ll x, ll y, ll z) {
        return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
    };
    auto solve = [&](vector<ll> a, vector<ll> b, vector<ll> c) {
        ll res = LLONG_MAX;
        for (ll i = 0; i < sz(c); ++i) c[i] *= 2;
        for (ll i = 0; i < sz(a); ++i) {
            ll R = a[i];
            auto G = closest(b, R);
            ll G1 = G.first, G2 = G.second;
            auto B = closest(c, R + G1);
            auto B_ = closest(c, R + G2);
            ll B1 = B.first, B2 = B.second, B3 = B_.first, B4 = B_.second;
            amin(res, val(R, G1, B1 / 2));
            amin(res, val(R, G2, B1 / 2));
            amin(res, val(R, G1, B2 / 2));
            amin(res, val(R, G2, B2 / 2));
            amin(res, val(R, G1, B3 / 2));
            amin(res, val(R, G2, B3 / 2));
            amin(res, val(R, G1, B4 / 2));
            amin(res, val(R, G2, B4 / 2));
        }
        return res;
    };
    // make almost equal, for each r, choose smallest g >= r, then b is lowerbound mean
    ll nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<ll> rr(nr), gg(ng), bb(nb);
    for (ll &R : rr) cin >> R;
    for (ll &G : gg) cin >> G;
    for (ll &B : bb) cin >> B;
    sort(all(rr)), sort(all(gg)), sort(all(bb));
    cout << min({solve(rr, gg, bb), solve(gg, bb, rr), solve(bb, rr, gg)}) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}