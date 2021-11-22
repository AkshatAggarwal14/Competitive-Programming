#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
auto sz = [](const auto &container) -> ll { return container.size(); };
#define all(x) (x).begin(), (x).end()

// bin search for first true
ll find_last_true(ll l, ll r, const auto &pred) {
    --l, ++r;
    for (ll m; m = (l + r) / 2, r > l + 1;) (pred(m) ? l : r) = m;
    return l;
}

vector<ll> vals;

string toBinary(ll n) {
    string s = bitset<64>(n).to_string();
    const auto pos = s.find('1');
    if (pos != string::npos) return s.substr(pos);
    return "0";
}

void fill() {
    for (ll i = 1; i <= 1000; ++i) {
        string s = toBinary(i);
        string s_ = s;
        reverse(all(s_));
        if (s == s_) vals.push_back(i);
    }
}

void Solution() {
    ll n, c = 0;
    cin >> n;
    vector<ll> res;
    while (n) {
        c = find_last_true(0LL, sz(vals) - 1, [&](ll m) { return vals[m] <= n; });
        res.push_back(vals[c]);
        n -= vals[c];
    }
    cout << sz(res) << '\n';
    for (auto &x : res) cout << x << ' ';
    cout << '\n';
}

//-------------------------------------------------------------------------

ll binary_palin(ll n) {
    ll res = 1;
    while (res < n) res *= 2;
    return res / 2;
}

void Better() {
    ll n, r;
    cin >> n;
    vector<ll> res;
    while (n) {
        r = binary_palin(n);  // 1000...01
        n -= (r + 1);
        if (r == 1) {
            res.push_back(1), res.push_back(1);
            break;
        }
        res.push_back(r + 1);
    }
    cout << res.size() << '\n';
    for (ll &x : res) cout << x << ' ';
    cout << '\n';
}

int main() {
    fill();
    cin.tie(nullptr)->sync_with_stdio(false);
    ll tc;
    cin >> tc;
    while (tc--) Better();
    return 0;
}