/*
    Given a building with F floors, and E eggs. Find the minimum number of attempts in worst case to find the critical floor[Threshold floor].

    If kth floor is threshold floor, egg will break on floor > k, and wont break on floor <= k.
    On a given floor either egg will break, or it will not
    ? If egg breaks, check floors below with 1 less egg.
    ? If egg does not break, then check floors above with same number of eggs.
*/

#include "Akshat.hpp"
const int INF = INT_MAX;

int32_t main() {
    int eggs, floors;
    cin >> eggs >> floors;
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, -1));
    function<int(int, int)> attempts = [&](int e, int f) {
        if (e == 1) return f;  // go from below, until it breaks
        if (f <= 1) return f;
        int &ans = dp[e][f];
        if (ans != -1) return ans;
        ans = INF;
        for (int k = 1; k <= f; ++k) {
            int egg_breaks = attempts(e - 1, k - 1);
            int egg_does_not_break = attempts(e, f - k);
            int temp_ans = 1 + max(egg_breaks, egg_does_not_break);  // 1 attempt + max coz worst case
            ans = min(ans, temp_ans);                                // minimum number of attempts
        }
        return ans;
    };
    cout << attempts(eggs, floors) << '\n';
    return 0;
}
