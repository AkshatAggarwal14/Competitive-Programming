#include <bits/stdc++.h>
using namespace std;

// ternary search
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

    auto f = [&](double pos) {
        double time = 0;
        for (ll i = 0; i < n; ++i) {
            double here = abs(double(a[i]) - pos) / double(v[i]);
            time = max(time, here);
        }
        return time;
    };

    double l = 0, r = 1e9 + 1;
    for (ll _ = 0; _ < 200; ++_) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);  // evaluates the function at m1
        double f2 = f(m2);  // evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }

    cout << fixed << setprecision(9) << f(l) << '\n';
}