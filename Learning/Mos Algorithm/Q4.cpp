// https://codeforces.com/problemset/problem/86/D
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// fix for compiler optimization
const int block_size = 450;  // sqrt(N)
const int N = 200005;
const int MX = 1E6 + 5;

ll a[N], cnt[MX];
ll ans;

struct Query {
    int l, r, idx;
    Query() = default;
    Query(int L, int R, int i) : l(L), r(R), idx(i) {}
    bool operator<(const Query &other) const {
        if (l / block_size != other.l / block_size) return l < other.l;
        return ((l / block_size) & 1) ? r < other.r : r > other.r;
    }
};

void remove(int idx) {
    ans -= cnt[a[idx]] * cnt[a[idx]] * a[idx];
    --cnt[a[idx]];  // reduce count
    ans += cnt[a[idx]] * cnt[a[idx]] * a[idx];
}

void add(int idx) {
    ans -= cnt[a[idx]] * cnt[a[idx]] * a[idx];
    ++cnt[a[idx]];  // increase count
    ans += cnt[a[idx]] * cnt[a[idx]] * a[idx];
}

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(nullptr)->sync_with_stdio(false);

    ans = 0;
    memset(cnt, 0, sizeof(cnt));

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r - 1, i};
    }
    vector<ll> res = mo_s_algorithm(queries);
    for (auto &x : res)
        cout << x << '\n';
}