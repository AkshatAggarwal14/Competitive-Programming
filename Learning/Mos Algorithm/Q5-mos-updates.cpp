// https://www.spoj.com/problems/XXXXXXXX/
// Mos Algorithm with updates + Coordinate compression
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TODO: to fix optimal block_size for compiler optimization
const int block_size = 1400;  // N^(2/3)
const int N = 50005;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
// cnt[3N] as 2N updates can change increase 2N values thus add 2N higher values to coordinate compression
int a[N], cnt[3 * N], temp[N];  // for calculating previous values
ll ans;
// to store compressed values to decrease runtime
int compressed[N];

// timer means number of updates yet
struct Query {
    int idx, l, r, updatesTillNow;
    Query() = default;
    Query(int i, int L, int R, int upds) : idx(i), l(L), r(R), updatesTillNow(upds) {}
    bool operator<(const Query &other) const {
        if (l / block_size != other.l / block_size) return l < other.l;
        if (r / block_size != other.r / block_size) return ((l / block_size) & 1) ? r < other.r : r > other.r;
        return (((l / block_size) & 1) ^ ((other.l / block_size) & 1))
                   ? updatesTillNow < other.updatesTillNow
                   : updatesTillNow > other.updatesTillNow;
    }
    // to debug
    friend string to_string(const Query &q) {
        stringstream ss;
        ss << "\nQuery(" << q.idx << ", " << q.l << ", " << q.r << ", " << q.updatesTillNow << ")\n";
        return ss.str();
    }
};

struct Update {
    // store old and new_compressed_values in update to decrease runtime
    int idx, old_value, new_value, old_compressed_value, new_compressed_value;
    Update() = default;
    Update(int id, int oval, int nval) : idx(id), old_value(oval), new_value(nval) {}
    // to debug
    friend string to_string(const Update &u) {
        stringstream ss;
        ss << "\nUpdate(" << u.idx << ", " << u.old_value << ", " << u.new_value << ")\n";
        return ss.str();
    }
};

// TODO: do the update given in argument, and modify answer if within current range
void doUpdate(Update &update, int cur_l, int cur_r) {
    if (update.idx >= cur_l && update.idx <= cur_r) {
        --cnt[update.old_compressed_value];
        if (cnt[update.old_compressed_value] == 0) {
            ans -= a[update.idx];
        }
    }
    a[update.idx] = update.new_value;
    compressed[update.idx] = update.new_compressed_value;
    if (update.idx >= cur_l && update.idx <= cur_r) {
        if (cnt[update.new_compressed_value] == 0) {
            ans += a[update.idx];  // add updated value
        }
        ++cnt[update.new_compressed_value];
    }
}

// TODO: rollback the update given in argument, and modify answer if within current range
void undoUpdate(Update &update, int cur_l, int cur_r) {
    if (update.idx >= cur_l && update.idx <= cur_r) {
        --cnt[update.new_compressed_value];
        if (cnt[update.new_compressed_value] == 0) {
            ans -= a[update.idx];
        }
    }
    a[update.idx] = update.old_value;
    compressed[update.idx] = update.old_compressed_value;
    if (update.idx >= cur_l && update.idx <= cur_r) {
        if (cnt[update.old_compressed_value] == 0) {
            ans += a[update.idx];  // add updated value
        }
        ++cnt[update.old_compressed_value];
    }
}

// TODO: remove value at idx from data structure
void remove(int idx) {
    --cnt[compressed[idx]];
    if (cnt[compressed[idx]] == 0) {
        ans -= a[idx];
    }
}

// TODO: add value at idx from data structure
void add(int idx) {
    if (cnt[compressed[idx]] == 0) {
        ans += a[idx];
    }
    ++cnt[compressed[idx]];
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
            doUpdate(updates[updatesDoneTillNow], cur_l, cur_r);
            ++updatesDoneTillNow;
        }
        // Undo Updates
        while (updatesDoneTillNow > q.updatesTillNow) {
            --updatesDoneTillNow;
            undoUpdate(updates[updatesDoneTillNow], cur_l, cur_r);
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
    unordered_map<int, int> compress;
    // need compressed value for array elements, old, and updated values
    vector<int> vals;
    for (int i = 0; i < n; ++i) vals.push_back(a[i]);
    for (Update &u : updates) vals.push_back(u.old_value), vals.push_back(u.new_value);
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    for (int i = 0; i < int(vals.size()); ++i) compress[vals[i]] = i + 1;
    for (int i = 0; i < n; ++i) {
        compressed[i] = compress[a[i]];
    }
    for (Update &u : updates) {
        u.old_compressed_value = compress[u.old_value];
        u.new_compressed_value = compress[u.new_value];
    }
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
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        temp[i] = a[i];
    }

    cin >> q;
    vector<Query> queries;
    vector<Update> updates;
    for (int i = 0; i < q; ++i) {
        char type;
        cin >> type;
        if (type == 'Q') {
            int x, y;
            cin >> x >> y, --x, --y;
            queries.push_back(Query(int(queries.size()), x, y, int(updates.size())));
        } else {
            int x, y;
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