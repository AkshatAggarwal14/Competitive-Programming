struct weighted_graph {
    ll n;
    vector<vector<pair<ll, ll>>> g;
    vector<ll> d, pred;
    bool called;
    weighted_graph(ll vertices, ll edges = 0)
        : n(vertices), g(n), d(n, INF), pred(n, -1), called(false) {
        read(edges);
    }
    void read(ll edges) {
        for (ll i = 0, u, v, w; i < edges; ++i) {
            cin >> u >> v >> w, --u, --v;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    void dijkstra(ll source) {
        if (!called) {
            called = true;
            d[source] = 0;
            set<pair<ll, ll>> s = {{0, source}};  // {distance, node}
            while (!s.empty()) {
                ll from = s.begin()->second;
                s.erase(s.begin());
                for (auto &child : g[from]) {
                    ll to = child.first;
                    ll len = child.second;
                    if (d[to] > d[from] + len) {
                        s.erase({d[to], to});
                        d[to] = d[from] + len;
                        pred[to] = from;
                        s.insert({d[to], to});
                    }
                }
            }
        }
    }
    vector<ll> path(ll source, ll destination) {
        if (!called) dijkstra(source);
        vector<ll> path;
        ll X = destination;
        while (X != -1) {
            path.push_back(X);
            if (X == source) break;
            X = pred[X];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
