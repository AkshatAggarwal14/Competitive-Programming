/*
    ? It involves dividing an array/string into parts to calculate temporary answer, and then using those temporary answers to find actual answer.
    ? find best ans[j, k] using merge(ans[j, i], ans[i + 1, k]) for all i in [j, k]

    ? FORMAT:
    int solve(int arr[], int l, int r) {
        ! Base case
        if (l > r) return 0; // Invalid Input
        if (l == r) return arr[l];  // Smallest Valid Input

        ! initialise ans[j, k]
        for(int i = l; i <= r; i++) {
            int left = solve(arr, l, i);
            int right = solve(arr, i + 1, r);
            tempans = f(left, right);

            ! update ans[j, k]
            if (tempans < ans[j, k]) ans[j, k] = tempans;
        }
        return ans[j, k];
    }
*/

/**
 * Problem statement: Calculate minimum cost (minimum number of operations) to multiply matrices with given dimensions.
 * A1A2A3A4 = ((A1(A2A3))A4) <- there can be multiple orders
 * A1[2 x 3], A2[3 x 6] -> cost = 2 x 3 x 6 = 36
 *
 * Let us have matrices A_1, A_2, .. with dimensions stored in arr[] with n + 1 elements and A_i has dimensions arr[i - 1] x arr[i]
 * * FIND MINIMUM COST
 */

#ifdef LOCAL
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = long long;
auto sz = [](const auto &container) { return int(container.size()); };
#define all(x) begin(x), end(x)

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353

void test() {
    int n;
    cin >> n;                // n matrices
    vector<int> arr(n + 1);  // a[i] has dimensions arr[i - 1] * arr[i]
    for (auto &it : arr) cin >> it;
    int mini = INF;
    auto cost = [&](const auto &self, ll i, ll j) -> int {
        if (i >= j) return 0;  // if equal, 1 index, impossible as 2 dimensions needed
        for (int k = i; k < j; ++k) {
            //! [i, j - 1] as if we reach j, then the 2nd set will be empty
            //! now make sure to divide into 2 matrices
            int left = self(self, i, k);
            int right = self(self, k + 1, j);
            int multiply_both = arr[i - 1] * arr[k] * arr[j];
            int temp = left + right + multiply_both;
            mini = min(mini, temp);
        }
        return mini;
    };
    cost(cost, 1, n);  // n - 1 as [arr[0], arr[1]] represent dimensions of first matrix
}

/**
 * either move k from [i, j - 1] and break into [i, k] and [k + 1, j]
 * ^ Here first partition is [i, k] as if k is i, we still have one matrix in left partition
 * second partition is [k + 1, j] as if k is j - 1, as j is atmost n - 1, we still have one matrix in right partition
 *
 *
 * either move k from [i + 1, j] and break into [i, k - 1] and [k, j]
 */

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    [[maybe_unused]] FILE *in = freopen("input.txt", "r", stdin);
    [[maybe_unused]] FILE *out = freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    // cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
