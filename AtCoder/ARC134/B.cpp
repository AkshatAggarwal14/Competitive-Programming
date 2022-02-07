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

void Solution() {
	ll n; cin >> n;
	string s; cin >> s;
	vector<vector<ll>> v(26);
	for (ll i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);
	for (ll i = 0; i <= 25; i++) reverse(all(v[i]));
	ll index = n;
	for (ll i = 0; i < index; i++) {
		for (char ch = 'a'; ch < s[i]; ++ch) { // loop breaks after swap
			auto it = upper_bound(all(v[ch - 'a']), index, greater<>()) - v[ch - 'a'].begin();
			if (it == sz(v[ch - 'a']) || v[ch - 'a'][it] <= i) continue;
			swap(s[i], s[v[ch - 'a'][it]]);
			index = v[ch - 'a'][it];
		}
	}
	cout << s;
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