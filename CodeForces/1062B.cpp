#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using ll = int64_t;
using str = string;
template <class T>
using v = vector<T>;
using vl = v<ll>;
using vvl = v<vl>;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll nextPowerOf2(ll n) {
    ll p = 1;
    if (n && !(n & (n - 1)))
        return n;
    while (p < n)
        p <<= 1;
    return p;
}

vector<pair<ll, ll>> divisors(ll n) {
    vector<pair<ll, ll>> ans;
    ll temp = n;
    for (ll i = 2; i <= temp; ++i) {
        if (n == 1) return ans;
        if (n % i == 0) {
            ll ctr = 0;
            while (n % i == 0) {
                ctr++;
                n /= i;
            };
            ans.emplace_back(i, ctr);
        }
    }
    return ans;
}

void Solution(ll _i) {
    // cout << "Case #" << _i << ": ";
    ll n;
    cin >> n;
    vector<pair<ll, ll>> div = divisors(n);  // {pf, cnt}
    dbg(div);
    // we can multiply all required at once and then sqrt again and again
    ll mini = 1, res = 0;
    set<ll> vals;
    for (auto [x, y] : div) {
        mini *= x;
        vals.insert(y);
        res = max(res, nextPowerOf2(y));
    }

    // If all y have same value i.e. == res
    if (sz(vals) == 1 && *vals.begin() == res) {
        ll temp = n;
        while (temp % mini == 0)
            temp /= mini;
        if (temp == 1) return void(cout << mini << " " << __lg(res) << '\n');
    }

    if (mini != n && sz(div))
        cout << mini << " " << 1 + __lg(res) << '\n';
    else
        cout << n << " " << 0 << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; ++i) Solution(i);
    return 0;
}