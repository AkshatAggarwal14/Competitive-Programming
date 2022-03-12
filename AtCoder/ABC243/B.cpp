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

void test() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll c = 0, d = 0;
    set<ll> st;
    for (ll &A : a) cin >> A, st.insert(A);
    for (ll &B : b) cin >> B;
    for (ll i = 0; i < n; ++i) {
        if (st.count(b[i])) ++d;
        if (a[i] == b[i]) ++c;
    }
    cout << c << '\n'
         << d - c << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    std::cout.rdbuf(cout.rdbuf()), std::cin.rdbuf(cin.rdbuf());
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
