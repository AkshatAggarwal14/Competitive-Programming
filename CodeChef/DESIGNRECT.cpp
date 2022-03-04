#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void Solution() {
    ll p, q;
    cin >> p >> q;
    vector<vector<ll>> vec(p + 1, vector<ll>(q + 1));
    ll f = 1;
    ll num = 0;
    ll up = 1, down = p, left = 1, right = q;
    while (1) {
        ll curr;
        if (f == 0) {
            curr = 0;
        } else {
            curr = num + 1;
            num++;
            if (curr > 9) {
                curr = 9;
            }
        }
        if (up > down or left > right) {
            break;
        }
        for (ll i = left; i <= right; i++) {
            vec[up][i] = curr;
            vec[down][i] = curr;
        }

        for (ll i = up; i <= down; i++) {
            vec[i][left] = curr;
            vec[i][right] = curr;
        }
        left++, right--;
        up++, down--;
        f = 1 - f;
    }

    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= q; j++) {
            cout << vec[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        Solution();
    }
    return 0;
}