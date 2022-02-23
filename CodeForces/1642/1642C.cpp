#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

/*
multiset::count(x) is O(log(n) + cnt[x]) //! DONT USE CAN TLE
multiset::contains(x) is O(log(n))

! USE MAP INSTEAD
*/

void Solution() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    multiset<ll> st;
    for (ll &A : a) cin >> A, st.insert(A);
    sort(all(a));
    for (ll i = 0; i < n; ++i) {
        if (st.contains(a[i]) && st.contains(a[i] * x)) {
            st.erase(st.lower_bound(a[i]));
            st.erase(st.lower_bound(a[i] * x));
        }
    }
    cout << sz(st) << '\n';
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