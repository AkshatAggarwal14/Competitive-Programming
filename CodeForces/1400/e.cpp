#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;

    // operation 1: subtract -1 from subarray
    // operation 2: convert given element into anything else
    // it is always optimal to either apply op1 on entire subarray or op2, and never both together
    // when we apply op1, apply it until an element becomes 0

    // O(n^2) as [1, n] -> [2, n] -> ... and each range in O(n)
    function<ll(int, int)> dfs = [&](int l, int r) {
        if (l > r) return 0LL;
        ll mini = *min_element(a.begin() + l, a.begin() + r + 1);
        // we will apply type 1 operation (min a_i) times
        int idx = -1;
        for (int i = l; i <= r; ++i) {
            a[i] -= mini;
            if (a[i] == 0) idx = i;
        }
        // return minimum of our two options: solve recursively, or just apply type 2 operations to each element
        return min(mini + dfs(l, idx - 1) + dfs(idx + 1, r), ll(r - l + 1));
    };

    cout << dfs(0, n - 1) << '\n';
}