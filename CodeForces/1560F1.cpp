#ifndef ONLINE_JUDGE
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
#define dbg(...) 42
#endif
using namespace std;
using ll = int64_t;

set<ll> k1, k2;
void gen1() {
    for (char c = '1'; c <= '9'; ++c) {
        for (ll i = 1; i <= 12; ++i) {
            k1.insert(stoll(string(i, c)));
        }
    }
}

vector<string> helper(char ch1, char ch2) {
    vector<string> res;
    for (ll c1 = 1; c1 <= 11; ++c1) {
        for (ll c2 = 1; c2 <= 11; ++c2) {
            if (c1 + c2 <= 12) {
                res.push_back(string(c1, ch1) + string(c2, ch2));
            }
        }
    }
    return res;
}

void gen2() {
    for (char c1 = '0'; c1 <= '9'; ++c1) {
        for (char c2 = '0'; c2 <= '9'; ++c2) {
            if (c1 != c2) {
                vector<string> temp = helper(c1, c2);
                for (string &s : temp) {
                    do {
                        if (s[0] != '0') k2.insert(stoll(s));
                    } while (next_permutation(s.begin(), s.end()));
                }
            }
        }
    }
}

void Solution() {
    ll n, k;
    cin >> n >> k;
    if (k == 1)
        cout << *k1.lower_bound(n);
    else
        cout << min(*k2.lower_bound(n), *k1.lower_bound(n));
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    gen1();
    gen2();
    ll t;
    cin >> t;
    while (t--)
        Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}