#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    int tc = 1;
    cin >> tc;
    while (tc--) {
        cin >> s;
        int n = s.length();
        int cnt[26] = {};
        for (int i = 0; i < n; ++i) cnt[s[i] - 'a']++;
        int f1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] > 'a' + n - 1 || cnt[s[i] - 'a'] > 1) {
                f1 = 1;
            }
        }
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = s[i] - 'a' + 1;
        int f = 1;
        int i = 0, j = n - 1;
        while (i < j) {
            if (arr[j] == *max_element(arr.begin() + i, arr.begin() + j + 1))
                j--;
            else if (arr[i] == *max_element(arr.begin() + i, arr.begin() + j + 1))
                i++;
            else {
                f = 0;
                break;
            }
        }
        if (f1) {
            cout << "NO\n";
            continue;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}
