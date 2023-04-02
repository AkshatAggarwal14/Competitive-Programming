#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<double> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    auto can = [&](double d) {
        if (d < a[0]) return false;
        if (d < l - a[n - 1]) return false;
        for (int i = 1; i < n; ++i) {
            if (2 * d < a[i] - a[i - 1]) return false;
        }
        return true;
    };

    double L = -1, R = l + 1;
    // ans range = 1e9, for 1e9 precision, log2(1e18) iterations = 60
    for (int _ = 0; _ < 60; ++_) {
        double M = (L + R) / 2;
        if (can(M)) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << fixed << setprecision(9) << R << '\n';
}