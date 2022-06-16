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
    ll n, m;
    cin >> n >> m;
    vector<ll> p(2 * n);
    for (auto &i : p) cin >> i;
    vector<pair<ll, ll>> special(m);
    vector<ll> mark(2 * n, -1);
    for (auto &[x, y] : special) {
        cin >> x >> y, --x, --y;
        if (p[x] < p[y]) swap(x, y);
        mark[x] = y;
        mark[y] = x;
    }
    vector<ll> others;
    for (ll i = 0; i < 2 * n; ++i)
        if (mark[i] == -1) others.push_back(i);
    sort(all(special), [&](auto &A, auto &B) { return p[A.first] > p[B.first]; });
    sort(all(others), [&](auto &A, auto &B) { return p[A] > p[B]; });
    dbg(mark, others, special);
    ll t;
    cin >> t;
    if (t == 1) {
        dbg(others);
        for (ll i = 0; i < m; ++i) {
            cout << special[i].first + 1 << endl;
            ll q;
            cin >> q;
            assert(q == special[i].second + 1);
        }
        for (ll i = 0; i < sz(others); i += 2) {
            cout << others[i] + 1 << endl;
            ll q;
            cin >> q;
        }
    } else {
        reverse(all(others));
        reverse(all(special));
        for (ll i = 0; i < n; ++i) {
            dbg(mark, special, others);
            ll q;
            cin >> q, --q;
            while (!others.empty() && (mark[others.back()] == -2 || others.back() == q))
                others.pop_back();
            while (!special.empty()) {
                if (mark[special.back().first] == -2 || mark[special.back().second] == -2) {
                    special.pop_back();
                } else {
                    break;
                }
            }
            if (mark[q] < 0) {
                ll maxi = -INF;
                if (!others.empty()) {
                    if (maxi < p[others.back()])
                        maxi = others.back();
                }
                if (!special.empty()) {
                    if (maxi < p[special.back().first])
                        maxi = special.back().first;
                }
                cout << maxi + 1 << endl;
                if (mark[maxi] >= 0) mark[mark[maxi]] = -2;
                mark[maxi] = -2;
                if (mark[q] >= 0) mark[mark[q]] = -2;
                mark[q] = -2;
            } else {
                if (mark[mark[q]] == -2) {
                    ll maxi = -INF;
                    if (!others.empty()) {
                        if (maxi < p[others.back()])
                            maxi = others.back();
                    }
                    // choose largest -> special or not
                    cout << maxi + 1 << endl;
                    if (mark[maxi] >= 0) mark[mark[maxi]] = -2;
                    mark[maxi] = -2;
                    if (mark[q] >= 0) mark[mark[q]] = -2;
                    mark[q] = -2;
                } else {
                    cout << mark[q] + 1 << endl;
                    mark[mark[q]] = -2;  // visited
                    mark[q] = -2;
                }
            }
            dbg(mark, special, others);
        }
    }
}

int32_t main() {
    cout << fixed << setprecision(12);
    int tc = 1;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
