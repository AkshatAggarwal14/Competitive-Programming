// https://vjudge.net/problem/Toph-distinct-dishting
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// fix for compiler optimization
const int block_size = 2200;  // N^(2/3)
const int N = 1E5 + 5;

// cnt[2N] as N updates can change increase N values thus add N higher values to coordinate compression
ll a[N], cnt[2 * N], temp[N];  // for calculating previous values
ll ans;
unordered_map<ll, ll> compress;

// timer means number of updates yet
struct Query {
    int idx, l, r, updatesTillNow;
    Query() = default;
    Query(int i, int L, int R, int upds) : idx(i), l(L), r(R), updatesTillNow(upds) {}
    bool operator<(const Query &other) const {
        return make_tuple(l / block_size, r / block_size, updatesTillNow) < make_tuple(other.l / block_size, other.r / block_size, other.updatesTillNow);
    }
    friend string to_string(const Query &q) {
        stringstream ss;
        ss << "\nQuery(" << q.idx << ", " << q.l << ", " << q.r << ", " << q.updatesTillNow << ")\n";
        return ss.str();
    }
};

struct Update {
    int idx;
    ll old_value, new_value;
    Update() = default;
    Update(int id, ll oval, ll nval) : idx(id), old_value(oval), new_value(nval) {}
    friend string to_string(const Update &u) {
        stringstream ss;
        ss << "\nUpdate(" << u.idx << ", " << u.old_value << ", " << u.new_value << ")\n";
        return ss.str();
    }
};

void remove(int idx) {
    if (a[idx] % 3) return;
    --cnt[compress[a[idx]]];
    if (cnt[compress[a[idx]]] == 0) {
        ans -= a[idx];
    }
}

void add(int idx) {
    if (a[idx] % 3) return;
    if (cnt[compress[a[idx]]] == 0) {
        ans += a[idx];
    }
    ++cnt[compress[a[idx]]];
}

vector<ll> mo_s_algorithm(vector<Query> &queries, vector<Update> &updates) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());
    int cur_l = 0, cur_r = -1;
    int updatesDoneTillNow = 0;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query &q : queries) {
        // Do Updates
        while (updatesDoneTillNow < q.updatesTillNow) {
            Update &update = updates[updatesDoneTillNow];
            if (update.idx >= cur_l && update.idx <= cur_r) {
                remove(update.idx);
            }
            a[update.idx] = update.new_value;
            if (update.idx >= cur_l && update.idx <= cur_r) {
                add(update.idx);  // add updated value
            }
            ++updatesDoneTillNow;
        }
        // Undo Updates
        while (updatesDoneTillNow > q.updatesTillNow) {
            --updatesDoneTillNow;
            Update &update = updates[updatesDoneTillNow];
            if (update.idx >= cur_l && update.idx <= cur_r) {
                remove(update.idx);
            }
            a[update.idx] = update.old_value;
            if (update.idx >= cur_l && update.idx <= cur_r) {
                add(update.idx);  // add updated value
            }
        }
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = ans;
    }
    return answers;
}

void coordinateCompress(int n, vector<Update> &updates) {
    // need compressed value for array elements, old, and updated values
    vector<ll> vals;
    for (int i = 0; i < n; ++i) vals.push_back(a[i]);
    for (Update &u : updates) vals.push_back(u.old_value), vals.push_back(u.new_value);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 0; i < int(vals.size()); ++i) compress[vals[i]] = i + 1;
}

int32_t main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    ans = 0;
    memset(cnt, 0, sizeof(cnt));

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        temp[i] = a[i];
    }

    vector<Query> queries;
    vector<Update> updates;
    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;
        if (type == '1') {
            int x, y;
            cin >> x >> y, --x, --y;
            queries.push_back(Query(int(queries.size()), x, y, int(updates.size())));
        } else {
            int x;
            ll y;
            cin >> x >> y, --x;
            updates.push_back(Update(x, temp[x], y));
            temp[x] = y;
        }
    }

    coordinateCompress(n, updates);

    vector<ll> res = mo_s_algorithm(queries, updates);
    for (auto &x : res)
        cout << x << '\n';
}