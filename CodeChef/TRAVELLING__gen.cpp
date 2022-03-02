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

mt19937 rng(uint32_t(chrono::steady_clock::now().time_since_epoch().count()));
#define uid(a, b) uniform_int_distribution<ll>(a, b)(rng)

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string randomString(ll length) {
    string res = "";
    for (ll i = 0; i < length; ++i) {
        ll choice = uid(0, int(alphabet.length()) - 1);
        res += alphabet[choice];
    }
    return res;
}

void Solution() {
    cout << "1\n";
    ll n = uid(10, 20);
    ll m = uid(2, n);
    set<pair<ll, ll>> st;
    cout << n << ' ' << m << '\n';
    while (sz(st) < m) {
        ll u = uid(1, n - 1);
        ll v = uid(u + 1, n);
        if (!st.count({u, v})) {
            st.insert({u, v});
            cout << u << ' ' << v << '\n';
        }
    }
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