#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    // 1092F - rerooting
    // https://codeforces.com/contest/1092/problem/F
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &A : a) cin >> A;
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    vector<ll> subtree(n), subtree_ans(n);
    function<void(ll, ll)> preprocess = [&](ll node, ll par) {
        subtree[node] = a[node];
        for (auto &child : g[node]) {
            if (child == par) continue;
            preprocess(child, node);
            subtree[node] += subtree[child];
            subtree_ans[node] += subtree_ans[child] + subtree[child];
        }
    };

    preprocess(0, -1);  // calculate dp[1]
    ll sum = subtree[0];
    function<void(ll, ll)> dfs = [&](ll node, ll par) {
        for (auto &child : g[node]) {
            if (child == par) continue;

            ll cost_without_child_subtree = subtree_ans[node] - (subtree_ans[child] + subtree[child]);
            // first remove childs, ans SAME AS how we added it
            // now to calculate ans for child,
            // add cost without this child and then push it down 1 level by adding sum of all values out of this subtree
            subtree_ans[child] += cost_without_child_subtree + (sum - subtree[child]);
            // now child has become root.
            dfs(child, node);
        }
    };

    dfs(0, -1);  // calculate dp[2]..dp[N] in O(N)
    cout << *max_element(subtree_ans.begin(), subtree_ans.end()) << '\n';
}