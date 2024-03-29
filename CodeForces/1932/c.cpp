#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    ll i;
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    string s;
    cin >> s;
    ll st = 0, end = n - 1;
    ll idx = 0;
    while (st <= end) {
        if (st == end)
            break;
        else if (s[idx] == 'L')
            st++;
        else
            end--;
        idx++;
    }
    if (s.back() == 'R')
        st = end - 1;
    else
        end = st + 1;

    reverse(s.begin(), s.end());

    idx = 0;
    ll ans = 1;
    vector<ll> vec;
    while (idx < n) {
        if (s[idx] == 'L') {
            ans *= arr[st];
            ans %= m;
            vec.push_back(ans);
            st--;
            idx++;
        } else {
            ans *= arr[end];
            ans %= m;
            vec.push_back(ans);
            end++;
            idx++;
        }
    }
    reverse(vec.begin(), vec.end());

    for (auto &x : vec)
        cout << x << " ";

    cout << "\n";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
