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
    string s;
    cin >> n >> s;
    ll ans = 0;
    while (s != "1" && !s.empty()) {
        if (s.back() == '0') {
            ++ans;
            s.pop_back();
        } else {
            ll L = sz(s) - 1;
            while (L >= 0 && s[L] == '1') {
                s[L] = '0';
                --L;
            }
            if (L != -1) s[L] = '1';
            ++ans;
        }
        dbg(s);
    }
    cout << ans << '\n';
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