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
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

// divide [0, 19] into 2 sets and handle 5 and 10 seperately
void test() {
    vector<ll> T = {-1, 1, 1, 2, 1, -1, 2, 2, 1, 2,
                    -1, 2, 2, 1, 2, -1, 1, 1, 2, 1};
    ll n;
    cin >> n;
    vector<ll> a(n);
    bool flag = false;
    for (auto &A : a) cin >> A, flag |= (A % 5 == 0);
    if (flag) {
        set<ll> st;
        for (auto &A : a) A += (A % 10), st.insert(A);
        cout << ((sz(st) > 1) ? "NO\n" : "YES\n");
        return;
    }
    set<ll> st;
    for (ll i = 0; i < n; ++i) {
        st.insert(T[a[i] % 20]);
        if (sz(st) > 1) return void(cout << "NO\n");
    }
    cout << "YES\n";
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
