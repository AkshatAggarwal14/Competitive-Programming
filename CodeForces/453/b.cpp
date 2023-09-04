#include <bits/stdc++.h>
using namespace std;

const int BITS = 17, N = 101, MX = 59;
int primes[BITS] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};  // primes <= 59
pair<int, int> dp[N][1 << BITS];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // dp[i][mask] = {minimum value until index in [1..i] with active primes in mask, last number}
    // vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(1 << BITS, {INT_MAX, -1}));
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << BITS); ++mask) {
            dp[i][mask] = {INT_MAX, -1};
        }
    }
    // b[i] <= 59 as abs(59-30) = abs(1-30) = 1

    vector<int> masks(MX + 1, 0);
    for (int num = 1; num <= MX; ++num) {
        for (int j = 0; j < BITS; ++j) {
            if (num % primes[j] == 0) {
                masks[num] |= (1 << j);
            }
        }
    }

    for (int beg = 1; beg <= MX; ++beg) {
        dp[0][masks[beg]] = min(dp[0][masks[beg]], {abs(a[0] - beg), beg});
    }

    for (int i = 1; i < n; ++i) {
        for (int prevMask = 0; prevMask < (1 << BITS); ++prevMask) {
            if (dp[i - 1][prevMask].first != INT_MAX) {
                dp[i][prevMask] = min(dp[i][prevMask], {dp[i - 1][prevMask].first + abs(a[i] - 1), 1});

                for (int last = 1; last <= MX; ++last) {
                    // gcd 1 of consecutive elements
                    if (((prevMask & masks[last]) == 0)) {
                        int curMask = (prevMask | masks[last]);
                        // minimise
                        dp[i][curMask] = min(dp[i][curMask], {dp[i - 1][prevMask].first + abs(a[i] - last), last});
                    }
                }
            }
        }
    }

    pair<int, int> t = {INT_MAX, -1};
    int sMask = -1;
    for (int mask = 0; mask < (1 << BITS); ++mask) {
        if (dp[n - 1][mask] < t) {
            t = dp[n - 1][mask];
            sMask = mask;
        }
    }

    deque<int> ans;
    int idx = n - 1;

    while (true) {
        ans.push_front(t.second);
        sMask ^= masks[t.second];
        --idx;
        if (idx < 0) break;
        t = dp[idx][sMask];
    }

    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}