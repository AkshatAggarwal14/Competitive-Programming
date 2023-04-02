#include <bits/stdc++.h>
using namespace std;

// find minimum time at which ranges they can travel to have something in common using binary search
using ll = long long;
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n), v(n);
    for (auto &x : a) cin >> x;
    for (auto &x : v) cin >> x;

    auto can = [&](double t) {
        // at time t, a[i] can go from [a[i] - t * v[i], a[i] + t * v[i]]
        double mn = 1E18, mx = -1E18;
        for (ll i = 0; i < n; ++i) {
            mn = min(mn, double(a[i]) + t * double(v[i]));
            mx = max(mx, double(a[i]) - t * double(v[i]));
        }
        return mx < mn;
    };

    double L = 0, R = 1E9;
    for (ll _ = 0; _ < 200; ++_) {
        double M = midpoint(L, R);
        if (can(M)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << fixed << setprecision(9) << R << '\n';
}