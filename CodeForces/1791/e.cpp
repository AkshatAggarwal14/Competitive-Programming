#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int negs = 0;
    ll sm = 0;
    for (auto &x : a) {
        cin >> x;
        if (x < 0) ++negs;
        x = abs(x);
        sm += x;
    }
    if (negs & 1) sm -= 2 * *min_element(a.begin(), a.end());
    cout << sm << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
}