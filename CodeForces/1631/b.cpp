#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    ll last = a[n - 1];
    auto cnt_from_back = [&]() -> ll {
        ll cnt = 0, pos = n - 1;
        while (pos >= 0 && a[pos] == last) ++cnt, --pos;
        return cnt;
    };
    ll ans = 0;
    while (true) {
        ll k = cnt_from_back();
        if (k == n) return void(cout << ans << '\n');
        for (ll i = 0; i < n && i < 2 * k; ++i)
            a[n - 1 - i] = last;
        ++ans;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}