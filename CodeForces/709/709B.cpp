#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, a;
    cin >> n >> a;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) cin >> x[i];

    sort(x.begin(), x.end());
    if (n == 1) return void(cout << 0 << '\n');  // n-1 = 0, so no steps needed

    ll ans = LLONG_MAX;
    auto best = [&](ll mn, ll mx) {
        if (a >= mn && a <= mx) {
            ans = min(ans, (mx - mn) + min(mx - a, a - mn));  // overlap when in between
        } else {
            set<ll> st = {mn, mx, a};
            ans = min(ans, *st.rbegin() - *st.begin());
        }
    };

    // Excluding 1 num, gives us only 3 choices for maximum and minimum
    vector<pair<ll, ll>> V = {{x[0], x[n - 1]}, {x[0], x[n - 2]}, {x[1], x[n - 1]}};
    for (auto [x, y] : V) best(x, y);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution();
    return 0;
}