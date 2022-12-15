#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e14;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    auto can = [&](ll S) {
        ll cnt = 0, sm = 0;
        for (auto &x : a) {
            sm += x;
            if (sm > S) {
                ++cnt;
                sm = x;
                if (sm > S) return false;
            }
        }
        if (sm) ++cnt;
        return cnt <= k;
    };
    ll L = 0, R = INF;
    --L, ++R;
    while (R > L + 1) {
        ll M = (L + R) / 2;
        if (can(M)) {
            R = M;  // as decreasing
        } else {
            L = M;
        }
    }
    cout << R << '\n';
}