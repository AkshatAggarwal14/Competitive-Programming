#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        // him[i] -- the smallest # of skip points required to kill bosses [i; n) if it's our friend's turn to move
        // us[i]  -- ......                                                       if it's our turn to move
        vector<ll> him(n + 1);
        vector<ll> us(n + 1);
        him[n] = us[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            // calculate him[i]
            him[i] = us[i + 1] + a[i];
            if (i + 2 <= n) him[i] = min(him[i], us[i + 2] + a[i] + a[i + 1]);

            // calculate us[i]
            us[i] = him[i + 1];
            if (i + 2 <= n) us[i] = min(us[i], him[i + 2]);
        }
        cout << him[0] << '\n';
    }
}