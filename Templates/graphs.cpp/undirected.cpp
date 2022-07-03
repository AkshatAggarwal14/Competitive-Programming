struct graph {
    vector<vector<ll>> adj;
    vector<ll> d;
    ll n;
    graph(ll &vertices) { n = std::forward<ll>(vertices), adj.resize(n), d.resize(n, -1); }
    void read(ll edges) {
        for (ll i = 0; i < edges; ++i) {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfs(ll parent) {
        if (d[parent] != -1) return;
        d[parent] = 1;
        for (ll &child : adj[parent]) {
            if (d[child] != -1) continue;
            d[child] = 1;
            dfs(child);
        }
    }
    void bfs(ll source) {
        queue<ll> q;
        q.push(source), d[source] = 0;
        while (!q.empty()) {
            ll parent = q.front();
            q.pop();
            for (ll &child : adj[parent]) {
                if (d[child] != -1) continue;
                d[child] = d[parent] + 1;
                q.push(child);
            }
        }
    }
    ll components() {
        ll res = 0;
        for (ll i = 0; i < n; ++i) {
            if (d[i] != -1) continue;
            dfs(i);
            res++;
        }
        return res;
    }
    friend ostream &operator<<(ostream &out, graph &obj) {
        for (ll i = 0; i < (ll)obj.adj.size(); ++i) {
            out << i << " -> {";
            for (ll j = 0; j < (ll)obj.adj[i].size(); ++j) {
                out << obj.adj[i][j];
                if (j != (ll)obj.adj[i].size() - 1) out << ", ";
            }
            out << "}\n";
        }
        return out;
    }
};