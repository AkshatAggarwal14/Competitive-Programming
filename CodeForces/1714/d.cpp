#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll MOD = 1e9 + 7;  // 998244353

// Function to select minimum number of pairs
// such that it covers the entire range [0, K]
vector<pair<ll, ll>> MinimumPairs(vector<pair<ll, ll>> arr, ll K) {
    int N = sz(arr);
    if (arr[0].first != 0) return {};
    int ans = 0;
    ll R = 0;
    vector<pair<ll, ll>> res;
    // Iterate in the range[0, N-1]
    for (int i = 0; i < N; i++) {
        if (R == K) break;
        ll maxr = -INF, f = -1;
        int j;
        for (j = i; j < N; j++) {
            if (arr[j].first <= R) {
                if (maxr < arr[j].second) {
                    f = arr[j].first;
                    maxr = arr[j].second;
                }
            } else {
                break;
            }
        }
        if (maxr == -INF) return {};
        res.push_back({f, maxr});
        i = j - 1;
        R = maxr;
        ans++;
    }

    // If the right bound
    // is not equal to K
    if (R != K) return {};
    return res;
}

void test() {
    string s;
    cin >> s;
    ll q;
    cin >> q;
    ll n = sz(s);
    vector<ll> val(n, 0);
    map<string, int> st;
    int z = 1;
    while (q--) {
        string t;
        cin >> t;
        st[t] = z++;
    }
    for (ll i = 0; i < n; ++i) {
        string tt = s.substr(i, 10);  // as atmost 10 length
        while (!tt.empty() && !st.count(tt)) tt.pop_back();
        val[i] = sz(tt);
    }
    // now we have starting point and length
    vector<pair<ll, ll>> r;
    for (int i = 0; i < n; ++i) {
        if (val[i]) r.push_back({i, i + val[i]});
    }
    // we now have ranges and we need to join minimum to make [0..n-1]
    if (r.empty()) return void(cout << "-1\n");
    auto ans = MinimumPairs(r, n);
    if (ans.empty()) return void(cout << "-1\n");
    cout << sz(ans) << '\n';
    for (auto &[x, y] : ans)
        cout << st[s.substr(x, y - x)] << ' ' << x + 1 << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
