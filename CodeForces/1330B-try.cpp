#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#define debug(...)
#endif

using str = string;
template <class T>
using v = vector<T>;
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
using ll = int;

bool check(multiset<ll> s) {
    return (sz(s) > 0 && *s.begin() == 1 && sz(s) == *s.rbegin() && sz(s) == sz(s));
}

void Solution() {
    ll n;
    cin >> n;
    multiset<ll> pref, suff;
    map<ll, ll> pref_cnt, suff_cnt;
    v<ll> arr(n);
    v<pair<ll, ll>> ans;
    fo(i, n) cin >> arr[i], suff.insert(arr[i]), ++suff_cnt[arr[i]];
    fo(i, n) {
        ++pref_cnt[arr[i]];
        --suff_cnt[arr[i]];
        if (suff_cnt[arr[i]] == 0) suff_cnt.erase(arr[i]);
        suff.erase(find(all(suff), arr[i]));
        pref.insert(arr[i]);

        dbg(pref, suff, suff_cnt, pref_cnt);
        if (check(pref) && check(suff) && sz(suff) == sz(suff_cnt) && sz(pref) == sz(pref_cnt)) ans.emplace_back(sz(pref), sz(suff));
    }
    cout << sz(ans) << '\n';
    for (auto [x, y] : ans) cout << x << " " << y << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) Solution();
    return 0;
}