// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "bits/stdc++.h"
using namespace std;
using ll = int;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, x, num, V;
    cin >> q >> x;
    vector<set<ll>> MEX(x);
    set<ll> vals;
    for (ll i = 0; i < q; ++i) MEX[i % x].insert(i), vals.insert(i);
    vals.insert(q);
    while (q--) {
        cin >> num;
        if (!MEX[num % x].empty()) {
            V = *MEX[num % x].begin();
            vals.erase(V);
            MEX[num % x].erase(V);
        }
        cout << *vals.begin() << '\n';
    }
    return 0;
}