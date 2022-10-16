#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "Akshat.hpp"
#else
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
    map<char, ll> s;
    map<char, ll, greater<ll>> t;
    s['a'] = t['a'] = 1;
    while (n--) {
        ll type, cnt;
        string x;
        cin >> type >> cnt >> x;
        if (type == 1) {
            for (auto &y : x) s[y] += cnt;
        } else {
            for (auto &y : x) t[y] += cnt;
        }
        vector<pair<char, ll>> v1(all(s)), v2(all(t));
        int i = 0;
        while (i < sz(v1) && i < sz(v2)) {
            if (v1[i].first < v2[i].first) {
                cout << "YES\n";
                break;
            } else if (v1[i].first > v2[i].first) {
                cout << "NO\n";
                break;
            } else {
                if (v1[i].second == v2[i].second) {
                    ++i;
                } else if (v1[i].second < v2[i].second) {
                    if (i == sz(v1) - 1) {
                        cout << "YES\n";
                        break;
                    } else {
                        cout << "NO\n";
                        break;
                    }
                } else {
                    if (i == sz(v2) - 1) {
                        cout << "NO\n";
                        break;

                    } else {
                        cout << "YES\n";
                        break;
                    }
                }
            }
        }
        if (i == sz(v1) && i == sz(v2))
            cout << "NO\n";
        else if (i == sz(v1))
            cout << "YES\n";
        else if (i == sz(v2))
            cout << "NO\n";
    }
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
