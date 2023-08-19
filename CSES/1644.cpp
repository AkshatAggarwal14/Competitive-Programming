#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

/**
 * max(pref[i] - pref[a], pref[i] - pref[a + 1], ... pref[i] - pref[b])
 * pref[i] - min(pref[a], pref[a + 1], ..., pref[b])
 * can do using monotonic stack
 */

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> ar(n);
    for (auto& x : ar) cin >> x;

    deque<ll> dq;

    auto insert = [&dq](ll new_element) {
        while (!dq.empty() && dq.back() > new_element)
            dq.pop_back();
        dq.push_back(new_element);
    };

    auto remove = [&dq](ll remove_element) {
        if (!dq.empty() && dq.front() == remove_element)
            dq.pop_front();
    };

    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i) pref[i] = pref[i - 1] + ar[i - 1];

    ll ans = LLONG_MIN;

    for (ll i = a; i <= b; ++i) {
        insert(pref[i - a]);
        ans = max({ans, pref[i], pref[i] - dq.front()});
    }

    for (ll i = b + 1; i <= n; ++i) {
        insert(pref[i - a]);
        remove(pref[i - b - 1]);
        ans = max(ans, pref[i] - dq.front());
    }

    cout << ans << '\n';
    return 0;
}
