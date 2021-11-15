#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };

set<ll> vals;
// numbers with adjacent digits - difference of 1
void recurse(string s, ll digit, ll n_digs) {
    if (digit == -1 || digit == 10 || n_digs == 8) return;
    if (s != "") vals.insert(stoll(s));
    recurse(s + char(digit + '0'), digit + 1, n_digs + 1);
    recurse(s + char(digit + '0'), digit - 1, n_digs + 1);
}

void Solution() {
    cerr << sz(vals) << '\n';
    ll x, y;
    cin >> x >> y;
    ll sum = 0;
    for (auto &e : vals) {
        if (e < x || e > y) continue;
        sum += e;
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (ll first_digit = 1; first_digit < 9; ++first_digit)
        recurse("", first_digit, 0);
    Solution();
    return 0;
}