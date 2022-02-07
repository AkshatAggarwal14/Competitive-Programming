// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
#define all(x) (x).begin(), (x).end()

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<ll> val(26);
    iota(all(val), 0);
    char a, b;
    for (ll i = 0; i < m; ++i) {
        cin >> a >> b;
        for (ll j = 0; j < 26; ++j) {
            if (val[j] == (a - 'a'))
                val[j] = (b - 'a');
            else if (val[j] == (b - 'a'))
                val[j] = (a - 'a');
        }
    }
    for (ll i = 0; i < n; ++i) s[i] = (char(val[s[i] - 'a'] + 'a'));
    cout << s << '\n';
    return 0;
}