#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i].first >> vec[i].second;
    // for(i = 0 ; i < n ; i++)
    // {
    //     if(vec[i].first > vec[i].second)
    //     swap(vec[i].first , vec[i].second);
    // }
    sort(vec.begin(), vec.end());
    map<ll, ll> mpp;
    for (auto &x : vec) {
        mpp[x.first] = x.second;
        mpp[x.second] = x.first;
    }
    set<ll> s;
    for (ll i = 1; i <= 2 * n; i++)
        s.insert(i);
    while (true) {
        if (s.size() == 0)
            break;
        bool ans = true;
        ll mx = 1e11;
        while (true) {
            if (s.size() == 0)
                break;
            ll p = *(s.begin());
            if (p > mx)
                break;
            ll q = mpp[p];
            if (p < mx && q > mx) {
                ans = false;
                break;
            }
            mx = min(mx, q);
            s.erase(s.find(p));
            s.erase(s.find(q));
            if (p > mx)
                break;
        }
        if (ans == false) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
