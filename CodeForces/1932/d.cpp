#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

void test() {
    int n;
    char trump;
    cin >> n >> trump;
    map<char, vector<string>> mp;
    for (int i = 0; i < 2 * n; ++i) {
        string s;
        cin >> s;
        mp[s[1]].push_back(s);
    }

    vector<string> others;

    vector<pair<string, string>> ans;
    for (auto &[suit, cards] : mp) {
        sort(cards.begin(), cards.end());
        if (suit != trump) {
            int m = int(cards.size());
            for (int i = 0; i + 1 < m; i += 2) {
                ans.push_back({cards[i], cards[i + 1]});
            }
            if (m & 1) {
                others.push_back(cards[m - 1]);
            }
        }
    }

    while (!mp[trump].empty() and !others.empty()) {
        ans.push_back({others.back(), mp[trump].back()});
        others.pop_back();
        mp[trump].pop_back();
    }

    int left = int(mp[trump].size());
    for (int i = 0; i + 1 < left; i += 2) {
        ans.push_back({mp[trump][i], mp[trump][i + 1]});
    }

    if (int(ans.size()) != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto &[x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
