// https://codeforces.com/contest/617/problem/E
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TODO: Find optimal block_size for compiler optimization
const int block_size = 317;  // sqrt(N) or N/sqrt(Q)
// TODO: Define constants needed for global variables (arrays etc. - The DS)
const int N = 1e6 + 5;

// TODO: initialize data structure, along with answer variable - can define get_answer() function also
int a[N], cnt[1 << 20], pref[N];
unsigned long long ans;
int k;

struct Query {
    int l, r, idx;
    Query() = default;
    Query(int L, int R, int i) : l(L), r(R), idx(i) {}
    bool operator<(const Query &other) const {
        if (l / block_size != other.l / block_size) return l < other.l;
        return ((l / block_size) & 1) ? r < other.r : r > other.r;
    }
};

// TODO: add value at idx from data structure
// number x occurs exactly x times
void add(int idx) {
    ans += cnt[a[idx] ^ k];
    ++cnt[a[idx]];
}

// TODO: remove value at idx from data structure
void remove(int idx) {
    --cnt[a[idx]];
    ans -= cnt[a[idx] ^ k];
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
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ans = 0;
    memset(cnt, 0, sizeof(cnt));

    int n, q;
    cin >> n >> q >> k;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];  // make prefix
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l - 1, r, i};
    }
    vector<ll> res = mo_s_algorithm(queries);
    for (auto &x : res)
        cout << x << '\n';
}

// count pref[j]^pref[i] = k for i,j in range [l-1,r]
// pref[j] = k^pref[i] -> count pairs using map