#include <bits/stdc++.h>
using namespace std;
#define int ll
#define all(c) begin(c), end(c)
using ll = long long;
const int MOD = 1e9 + 7, N = 1e5 + 10;
const int MX = 1e8;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < MX; i += 25) {  // check every multiple of 25
        string ss = to_string(i);
        if (ss.length() != s.length()) continue;
        set<int> st;
        int bad = 1;
        for (int j = 0; j < ss.length(); j++) {
            if (s[j] == '_') continue;
            if (s[j] == 'X') {
                st.insert(ss[j] - '0');
                if (st.size() > 1) break;
                continue;
            }
            if (s[j] != ss[j]) bad = 0;
        }
        ans += (st.size() <= 1 and bad);
    }
    cout << ans << '\n';
    return 0;
}