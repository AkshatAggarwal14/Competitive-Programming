#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define debug(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
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

void Solution() {
	ll n, l, w; cin >> n >> l >> w;
	vector<pair<ll, ll>> a;
	for (ll i = 0, x; i < n; ++i) cin >> x, a.emplace_back(x, x + w);
	a = merge(a);
	a.emplace_back(l , l);
	ll ans = 0;
	for (ll i = 0; i < sz(a); ++i) {
		ll len = a[i].first - ((i >= 1) ? a[i - 1].second : 0);
		ans += (len + w - 1) / w;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout << fixed << setprecision(12);
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		Solution();
	}
	return 0;
}