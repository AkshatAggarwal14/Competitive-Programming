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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    /*
    ? TECHNIQUE:
        ? dp[i] = length of longest subarray ending at ith element of array
        ? ans: max element in dp
        now to calculate dp[i], assume we know answers for all [0..i - 1]
        ? cases:  1. ans is a[i] only, dp[i] = 1
                2. we extend a subsequence before i such that a_j < a_i and j < i, dp[i] = dp[j] + 1
                   conditions for valid j:  A. j < i
                                            B. a_j < a_i

        maintain a DS of potential candidates, with (key, value) as (value, advantage extending it gives)
        ? Observations:
            1. If two elements provide same advantage, the larger value is useless, as any future "x" that can extend larger one can also extend smaller one.
            2. The potential candidate set contains values in sorted order and their advantages are also sorted.
                Proof:
                    Let us assume v_1 > v_2 and adv_1 < adv_2, then any future x which can extend v_1 can also extend v_2, and get more advantage.
                    Thus v_1 is useless and not meant to be in potential candidate set
            !3. The length of potential candidate set gives length of LIS
            !4. The Advantages of values are 1, 2, ...

    */

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> dp(n);
    dp[0] = 1;
    map<int, int> potential_candidates;
    potential_candidates[a[0]] = dp[0];

    auto get_largest = [&](int val) -> int {
        auto it = potential_candidates.lower_bound(val);  // smallest value >= val
        if (it == potential_candidates.begin()) return 0;
        --it;  // largest value < val
        return it->second;
    };

    auto insert = [&](int val, int advantage) {
        if (potential_candidates.count(val)) {
            if (potential_candidates[val] >= advantage) return;  // if already exists
        }
        potential_candidates[val] = advantage;
        auto it = potential_candidates.find(val);
        ++it;
        while (it != potential_candidates.end() && it->second <= advantage) {
            it = potential_candidates.erase(it);  // delete elements with larger value and less advantage
        }
    };

    for (int i = 1; i < n; ++i) {
        dp[i] = 1 + get_largest(a[i]);
        insert(a[i], dp[i]);
    }

    dbg(potential_candidates);
    cout << *max_element(all(dp)) << '\n';

    return 0;
}
