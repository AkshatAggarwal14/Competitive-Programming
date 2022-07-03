template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T, class G>
auto dijkstra(const G& g, int s) {
    std::vector d(g.size(), std::numeric_limits<T>::max());
    std::vector prv(g.size(), -1);
    min_heap<std::pair<T, int>> rh;
    rh.emplace(d[s] = 0, s);
    while (!rh.empty()) {
        auto [dv, v] = rh.top();
        rh.pop();
        if (dv != d[v]) continue;
        for (auto&& [to, w] : g[v]) {
            if (d[to] > dv + w) {
                d[to] = dv + w;
                rh.emplace(d[to], to);
                prv[to] = v;
            }
        }
    }
    return std::make_pair(d, prv);
}
