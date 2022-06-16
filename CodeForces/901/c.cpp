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
3
ab
de
aj

ans = a * (20) + d * (10) + b + e + j
now b, e or j can be 0
*/

void Solution() {
    vector<ll> cnt(11, 0);
    vector<bool> has_been_front(11, false);
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        has_been_front[s[0] - 'a'] = true;
        for (ll j = 0; j < sz(s); ++j)
            cnt[s[j] - 'a'] += static_cast<ll>(pow(10, sz(s) - 1 - j));
    }
    // this was done to make a 0
    ll idx = -1, max_val = -1;
    for (ll i = 0; i <= 10; ++i)
        if (!has_been_front[i])
            if (cnt[i] > max_val)
                idx = i, max_val = cnt[i];
    if (idx != -1) cnt[idx] = 0;
    vector<ll> ans;
    for (ll i = 0; i <= 10; ++i)
        if (cnt[i]) ans.push_back(cnt[i]);
    sort(all(ans), greater<ll>());
    ll res = 0;
    for (ll i = 0; i < sz(ans); ++i) res += (i + 1) * ans[i];
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}