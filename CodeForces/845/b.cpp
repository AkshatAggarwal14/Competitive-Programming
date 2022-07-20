#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    auto check = [](const string &x) {
        return (x[0] + x[1] + x[2] == x[3] + x[4] + x[5]);
    };
    int ans = 6;
    for (int i = 0; i <= 999999; ++i) {
        string t = to_string(i);
        reverse(t.begin(), t.end());
        while (int(t.size()) < 6) t.push_back('0');
        reverse(t.begin(), t.end());
        if (check(t)) {
            int cnt = 0;
            for (int j = 0; j < 6; ++j) cnt += (t[j] != s[j]);
            ans = min(ans, cnt);
        }
    }
    cout << ans << '\n';
}