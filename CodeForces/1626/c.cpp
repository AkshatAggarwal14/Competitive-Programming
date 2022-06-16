#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const ll MOD = 1e9 + 7;

vector<pair<ll, ll>> merge(vector<pair<ll, ll>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<pair<ll, ll>> ans;
    ll n = sz(intervals);
    ll i = 0;
    while (i < n) {
        ll x = intervals[i].first;
        ll y = intervals[i].second;
        while (i < n && y >= intervals[i].first) {
            y = max(y, intervals[i].second);
            i++;
        }
        ans.push_back({x, y});
    }
    return ans;
}

//https://leetcode.com/problems/merge-intervals/
void Better() {
    ll n;
    cin >> n;
    vector<ll> k(n), h(n);
    for (ll &K : k) cin >> K;
    for (ll &H : h) cin >> H;
    vector<pair<ll, ll>> intervals;
    // {start, end}
    // the problem needs to merge intervals, and calculate sum of 1 + 2 ... interval size for each merged one
    for (ll i = 0; i < n; ++i) intervals.push_back({k[i] - h[i] + 1, k[i]});
    intervals = merge(intervals);
    ll ans = 0;
    for (auto &[x, y] : intervals) {
        ll d = y - x + 1;
        ans += (d * (d + 1)) / 2;
    }
    cout << ans << '\n';
}

//! -----------------------------------------------------------------------

void Solution() {
    ll n;
    cin >> n;
    vector<ll> k(n), h(n);
    for (ll &K : k) cin >> K;
    for (ll &H : h) cin >> H;
    map<ll, ll> cnt;
    for (ll i = 0; i < n; ++i) {
        // multiply by 2 so, {4, 6}, {7, 7} doesnt get merged
        ++cnt[2 * (k[i] - h[i] + 1)];
        --cnt[2 * k[i] + 1];
    }
    vector<pair<ll, ll>> pref;
    ll sum = 0;
    for (auto &[x, y] : cnt) {
        sum += y;
        y = sum;
        pref.push_back({x, y});
    }
    ll ans = 0;
    for (ll i = 0, j = 0; i < sz(pref) && j < sz(pref);) {
        while (pref[j].second != 0) ++j;
        ll d = pref[j].first - pref[i].first + 1;
        d /= 2;
        ans += (d * (d + 1)) / 2;
        i = j + 1;
        j = i;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        // Solution();
        Better();
    }
    return 0;
}