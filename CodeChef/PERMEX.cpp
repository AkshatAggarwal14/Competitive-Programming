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
    string s;
    cin >> s;
    if (s[0] == '0' || s[n] == '0') return void(cout << "No\n");
    if (s[1] == '0') return void(cout << "No\n");
    vector<ll> ans, rev;
    for (ll i = 1, cnt = 0; i <= n; ++i) {
        if (s[i] == '1') {
            ans.push_back(cnt++);
            while (!rev.empty()) {
                ans.push_back(rev.back());
                rev.pop_back();
            }
        } else {
            rev.push_back(cnt++);
        }
    }
    cout << "Yes\n";
    for (ll &x : ans) cout << x << ' ';
    cout << '\n';
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