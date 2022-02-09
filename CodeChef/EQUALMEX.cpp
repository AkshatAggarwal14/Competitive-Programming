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

ll mex(const vector<ll> &x) {
    set<ll> st(all(x));
    for (ll i = 0; i < sz(x); ++i)
        if (!st.count(i)) return i;
    return sz(x);
}

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(2 * n), A, B;
    for (ll &A : a) cin >> A;
    sort(all(a), greater<ll>());
    for (ll i = 0; i < n; ++i) {
        A.push_back(a.back()), a.pop_back();
        B.push_back(a.back()), a.pop_back();
    }
    cout << ((mex(A) == mex(B)) ? "YES\n" : "NO\n");
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