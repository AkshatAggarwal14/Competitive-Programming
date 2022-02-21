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

bool checkPerm(vector<ll> p, ll id) {
    set<ll> st;
    for (ll i = 0; i <= id; ++i) {
        st.insert(p[i]);
    }
    for (ll i = 1; i <= id + 1; ++i)
        if (!st.count(i)) return false;
    return true;
}

void Solution() {
    ll t;
    cin >> t;
    ll n, k;
    cin >> n >> k;
    vector<ll> mark(n, 0), p(n);
    for (ll i = 0, num; i < k; ++i) {
        cin >> num;
        mark[num - 1] = 1;
    }
    for (ll &P : p) cin >> P;
    for (ll i = 0; i < n; ++i) {
        if (checkPerm(p, i) != mark[i]) return void(cout << "WA\n");
    }
    cout << "OK\n";
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