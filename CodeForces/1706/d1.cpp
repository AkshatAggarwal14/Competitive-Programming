#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tc;
    cin >> tc;
    while (tc--) {
        int ans = 1e9;
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &A : a) cin >> A;
        for (int v = 1; v <= a[0]; v++) {  // setting minimum value
            int closest = v;
            for (int i = 0; i < n; i++) {
                int p = min(k, a[i] / v);
                closest = max(closest, a[i] / p);
            }
            ans = min(ans, closest - v);
        }
        cout << ans << '\n';
    }
    return 0;
}