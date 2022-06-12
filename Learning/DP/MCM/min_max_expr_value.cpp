/*
    Find minimum and maximum value of expression by adding brackets
    s: 2+3*4
    ans:
    { min: [2 + (3 * 4)] = 14, max: [(2 + 3) * 4] = 20 }
*/

#include "Akshat.hpp"
const int INF = INT_MAX;
const int mINF = INT_MIN;

int32_t main() {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<vector<int>> dp_min(n, vector<int>(n, -1));
    vector<vector<int>> dp_max(n, vector<int>(n, -1));
    function<int(int, int)> max_val;
    function<int(int, int)> min_val = [&](int i, int j) {
        if (i > j) return INF;
        int &ans = dp_min[i][j];
        if (ans != -1) return ans;
        ans = INF;
        if (i == j) return ans = int(s[i] - '0');
        for (int k = i + 1; k <= j - 1; k += 2) {
            int lmin = min_val(i, k - 1);
            int rmin = min_val(k + 1, j);
            int rmax = max_val(k + 1, j);
            if (s[k] == '+')
                ans = min(ans, lmin + rmin);
            else if (s[k] == '*')
                ans = min(ans, lmin * rmin);
            else if (s[k] == '-')
                ans = min(ans, lmin - rmax);
            else if (s[k] == '/') {
                if (rmax == 0 || lmin % rmax) continue;
                ans = min(ans, lmin / rmax);
            }
        }
        return ans;
    };
    max_val = [&](int i, int j) {
        if (i > j) return mINF;
        int &ans = dp_max[i][j];
        if (ans != -1) return ans;
        if (i == j) return ans = int(s[i] - '0');
        ans = mINF;
        for (int k = i + 1; k <= j - 1; k += 2) {
            int lmax = max_val(i, k - 1);
            int rmax = max_val(k + 1, j);
            int rmin = min_val(k + 1, j);
            if (s[k] == '+')
                ans = max(ans, lmax + rmax);
            else if (s[k] == '*')
                ans = max(ans, lmax * rmax);
            else if (s[k] == '-')
                ans = max(ans, lmax - rmin);
            else if (s[k] == '/') {
                if (rmin == 0 || lmax % rmin) continue;
                ans = max(ans, lmax / rmin);
            }
        }
        return ans;
    };
    cout << min_val(0, n - 1) << '\n';
    cout << max_val(0, n - 1) << '\n';
    return 0;
}
