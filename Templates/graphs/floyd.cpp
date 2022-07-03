for (ll i = 0, u, v, wt; i < m; ++i) {
    cin >> u >> v >> wt, --u, --v;
    d[u][v] = wt;
    d[v][u] = wt;
}
for (ll i = 0; i < n; ++i) d[i][i] = 0;
// floyd warshall to calculate the distances
for (ll k = 0; k < n; ++k) {
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
