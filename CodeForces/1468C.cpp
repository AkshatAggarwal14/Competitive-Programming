#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
template <class T>
using pq = priority_queue<pl, vector<pl>, T>;
auto sz = [](const auto &container) -> ll { return container.size(); };

struct cmp2 {
    bool operator()(const pl &a, const pl &b) const {
        return a.second > b.second;
    }
};
struct cmp3 {
    bool operator()(const pl &a, const pl &b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //! money, index
    ll q;
    cin >> q;
    pq<cmp2> p2;  //idx
    pq<cmp3> p3;  //money
    vector<ll> vis{-1};
    ll type, m;

    auto go = [&]<typename T>(pq<T> &P) -> void {
        while (vis[P.top().second]) P.pop();
        vis[P.top().second] = 1;
        cout << P.top().second << ' ';
        P.pop();
    };

    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> m;
            p2.emplace(m, sz(vis)), p3.emplace(m, sz(vis));
            vis.push_back(0);
        } else if (type == 2)
            go(p2);
        else
            go(p3);
    }
    return 0;
}