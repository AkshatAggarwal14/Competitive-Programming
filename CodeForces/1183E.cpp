// #include "Akshat.hpp"
#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;

void Solution() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cnt = 0, cost = 0;
    queue<string> bfs;
    set<string> check;
    bfs.emplace(s);
    check.insert(s);
    while (!bfs.empty()) {
        string t = bfs.front();
        cnt++;
        cost += (n - t.length());
        if (cnt == k) {
            cout << cost << '\n';
            return;
        }
        bfs.pop();
        for (ll i = 0; i < t.length(); ++i) {
            string t2 = t;
            t2.erase(i, 1);
            if (!check.count(t2)) {
                bfs.emplace(t2);
            }
            check.insert(t2);
        }
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Solution();
    cerr << fixed << setprecision(4) << (double)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}