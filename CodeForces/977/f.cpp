#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> dp;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = max(dp[a[i]], 1 + dp[a[i] - 1]);  // if not present it will get 1
    }
    int largest = -1, len = 0;
    for (auto &[x, y] : dp) {
        if (y > len) {
            len = y;
            largest = x;
        }
    }
    cout << len << '\n';
    int val = largest - len + 1;  // first
    for (int i = 0; i < n; ++i) {
        if (a[i] == val) {
            cout << i + 1 << ' ';
            ++val;
        }
    }
    cout << '\n';
}