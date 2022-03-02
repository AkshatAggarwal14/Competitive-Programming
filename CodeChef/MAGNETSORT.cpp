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

void Solution() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &A : a) cin >> A;
    string s;
    cin >> s;

    if (is_sorted(all(a))) return void(cout << "0\n");
    if (s[0] != s[n - 1]) return void(cout << "1\n");

    ll S = count(all(s), 'S'), N = sz(s) - S;
    if (!S || !N) return void(cout << "-1\n");

    auto sorted(a);
    sort(all(sorted));

    ll l = -1, r = -1;
    for (ll i = 0; i < n; ++i)
        if (a[i] != sorted[i]) {
            l = i;
            break;
        }
    for (ll i = 0; i < n; ++i)
        if (a[i] != sorted[i]) r = i;

    ll L_N = s.find('N'), R_N = s.rfind('N');
    ll L_S = s.find('S'), R_S = s.rfind('S');
    if (L_N <= l && R_S >= r) return void(cout << "1\n");
    if (L_S <= l && R_N >= r) return void(cout << "1\n");

    cout << "2\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}