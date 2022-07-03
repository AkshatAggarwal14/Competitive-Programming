vector<ll> which_cycle(n, -1);
vector<vector<ll>> cycles;
ll cycle_number = 0;
for (ll i = 0; i < n; ++i) {
    ll par = p[i];
    if (which_cycle[par] != -1) continue;
    vector<ll> curr_cycle;
    while (which_cycle[par] == -1) {
        which_cycle[par] = cycle_number;
        curr_cycle.push_back(par);
        par = p[par];
    }
    cycles.push_back(curr_cycle);
    ++cycle_number;
}