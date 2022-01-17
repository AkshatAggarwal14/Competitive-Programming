#ifdef LOCAL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using ll = long long;
constexpr auto sz = [](const auto &container) -> ll { return ll(container.size()); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
constexpr bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
constexpr bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }

/*
mark u as visited
for v in the set of unvisited vertices:
    if v is not adjacent to u:
        dfs(v)
*/

// https://codeforces.com/blog/entry/93801

// O((n + m)log n) -> TLEs
void DFS() {
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> g(n);
    set<ll> unvis;
    for (ll i = 0; i < n; ++i) unvis.insert(i);

    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        u--, v--;
        g[u].insert(v), g[v].insert(u);
    }

    vector<vector<ll>> components;

    const auto dfs = [&](const auto &self, ll parent) {
        components.back().push_back(parent);  // in newly added component
        unvis.erase(parent);
        if (unvis.empty()) return;
        auto it = unvis.begin();
        while (true) {
            ll child = *it;
            // if not present then edge
            if (!g[parent].contains(child)) self(self, child);
            dbg(unvis, child, parent);
            it = unvis.upper_bound(child);  // next one in set
            if (it == unvis.end()) break;
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (unvis.contains(i)) {        // is unvisited
            components.emplace_back();  // add new empty component
            dfs(dfs, i);                // run dfs here
        }
    }

    cout << sz(components) << '\n';
    for (auto &c : components) {
        cout << sz(c) << ' ';
        for (auto &x : c) cout << x + 1 << ' ';
        cout << '\n';
    }
}

//! --------------------------------------------------------------------------

// https://codeforces.com/blog/entry/93801

/*
The first change is that we don't use a set, instead we use a vector to store unvisited vertices. Initially all the vertices are unvisited.

Let's see what happens when we process a vertex u

in this algorithm.

Firstly, we note down all the unvisited vertices that are adjacent to the vertex u
. Let's call them blocked vertices (for u), and mark them in a global array (we will unmark them when we finish the iteration corresponding to u).

Then we iterate over all the unvisited vertices, and we can push an unvisited vertex into the queue if and only if it is not u
and it is not blocked. Then the only remaining unvisited vertices are the ones that are blocked, so we replace the set of unvisited vertices by the set of blocked vertices.
*/

// O(n + m)
void BFS() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v), g[v].push_back(u);
    }

    vector<bool> mark_vis(n, false);
    vector<vector<ll>> components;
    vector<ll> unvis(n);
    iota(all(unvis), 0);  // all unvis
    vector<bool> unvisited_but_unreachable(n, false);
    queue<ll> bfs;

    for (ll i = 0; i < n; ++i) {
        if (mark_vis[i]) continue;
        components.emplace_back();
        components.back().push_back(i);
        mark_vis[i] = true;
        bfs.push(i);
        while (!bfs.empty()) {
            ll parent = bfs.front();
            bfs.pop();
            vector<ll> remaining_to_visit;

            // children adjacent to parent and arent visited yet, are blocked to be actually visited, and added to remaining_to_visit
            for (auto &child : g[parent])
                if (!mark_vis[child])
                    remaining_to_visit.push_back(child),
                        unvisited_but_unreachable[child] = true;  // blocked

            for (auto &child : unvis) {
                if (parent == child || unvisited_but_unreachable[child]) continue;
                mark_vis[child] = true;
                components.back().push_back(child);
                bfs.push(child);
            }
            // clear out the buffer, UNBLOCK
            for (auto &v : remaining_to_visit)
                unvisited_but_unreachable[v] = false;
            // size of remaining_to_visit is at most deg(u)
            // so complexity remains O(V + E)
            unvis = move(remaining_to_visit);
        }
    }

    cout << sz(components) << '\n';
    for (auto &x : components) {
        cout << sz(x) << ' ';
        for (auto &y : x) cout << y + 1 << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        // DFS();
        BFS();
    }
    return 0;
}