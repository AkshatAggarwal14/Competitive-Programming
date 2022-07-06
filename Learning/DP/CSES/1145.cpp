#include "bits/stdc++.h"
using namespace std;
auto sz = [](const auto &container) { return int(container.size()); };

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> dp;  // vector of potential candidates
    // we dont need to store advantages as they are 1, 2, ..
    // the position of value in potential set gives its advantage
    // ans = length of potential set at the end

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {  // if no element found add to potential candidates
            dp.push_back(a[i]);
        } else {
            *it = a[i];  // if found an element >= a[i], put a[i] in its position, replacing as a smaller value can be extended more than current value
        }
    }

    cout << sz(dp) << '\n';
    return 0;
}
