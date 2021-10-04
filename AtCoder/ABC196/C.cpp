#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll sTol(string num) {
    ll res = 0;
    for (char &c : num) {
        res = res * 10 + (c - '0');
    }
    return res;
}

const ll N = 1e6 + 5;
o_set<ll> vals;
void fill() {
    ll i = 1;
    string s;
    while (i < N) {
        s = to_string(i);
        s.append(s);
        vals.insert(sTol(s));
        i++;
    }
}

void Solution() {
    ll n;
    cin >> n;
    cout << vals.order_of_key(n + 1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fill();
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
