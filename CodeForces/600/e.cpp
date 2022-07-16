#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> col(n);
    for (ll &c : col) cin >> c;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<unordered_map<ll, ll>> cnt(n);  // cnt[i] = {{color, occurences}, ...} for node i
    vector<map<ll, ll>> occur(n);          // occur[i] = {{occurences, sum}, ...} for node i
    vector<ll> ans(n);
    //! small to large merging
    function<void(int, int)> dfs = [&](int node, int par) {
        occur[node][1] += col[node];
        ++cnt[node][col[node]];
        for (auto &child : g[node])
            if (child != par) {
                dfs(child, node);
                // small to large
                if (cnt[child].size() > cnt[node].size()) swap(cnt[child], cnt[node]),
                                                          swap(occur[child], occur[node]);

                // cnt[node] -> bigger map
                // cnt[child] -> smaller map
                // update answer, by adding occurences from smaller map to bigger map
                for (auto &[x, y] : cnt[child]) {
                    ll &occ_in_large = cnt[node][x];
                    if (occur[node].count(occ_in_large))
                        occur[node][occ_in_large] -= x;  // remove from old sum
                    occ_in_large += y;                   // merged
                    occur[node][occ_in_large] += x;      // add to new sum
                }
                cnt[child].clear();  // cleared
            }
        ans[node] = (occur[node].rbegin())->second;
    };
    dfs(0, -1);
    for (auto &x : ans) cout << x << ' ';
    cout << '\n';
}