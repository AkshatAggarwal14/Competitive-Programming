#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[2][N];

// int win(int turn, int leftStones, vector<int> &a, int &n) {
//     if (leftStones < 0) return 0;
//     if (leftStones == 0) return 1;

//     int &canWin = dp[turn][leftStones];
//     if (canWin != -1) return canWin;

//     canWin = 1;

//     for (int i = 0; i < n; ++i) {
//         if (win(turn ^ 1, leftStones - a[i], a, n)) {
//             canWin = 0;
//             break;
//         }
//     }

//     return canWin;
// }

// int main() {
//     memset(dp, -1, sizeof(dp));
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);
//     for (auto &x : a) cin >> x;
//     cout << (win(0, k, a, n) ? "Second" : "First") << '\n';
// }

int main() {
    memset(dp, 0, sizeof(dp));
    // dp[i][j] = check if ith player can win if there are j stones left
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    for (int kk = 0; kk <= k; ++kk) {
        for (int i = 0; i < n; ++i) {
            for (int turn = 0; turn < 2; ++turn) {
                if (!dp[turn][kk] && kk + a[i] <= k) {
                    dp[turn ^ 1][kk + a[i]] = 1;
                }
            }
        }
    }

    cout << (dp[0][k] ? "First" : "Second") << '\n';
}