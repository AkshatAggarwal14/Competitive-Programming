#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// LG[] array is slower due to cache misses

const ll N = 1e5 + 5, K = 16;
int a[N][5], st[N][K + 1][5];

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void init() {
    for (int i = 0; i < N; i++)
        for (int id = 0; id < 5; ++id)
            st[i][0][id] = a[i][id];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            for (int id = 0; id < 5; ++id)
                st[i][j][id] = max(st[i][j - 1][id], st[i + (1 << (j - 1))][j - 1][id]);
}

vector<int> query(int L, int R) {
    int j = log2_floor(R - L + 1);
    vector<int> ans(5, 0);
    for (int id = 0; id < 5; ++id) ans[id] = max(st[L][j][id], st[R - (1 << j) + 1][j][id]);
    return ans;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> a[i][j];
        for (int j = m; j < 5; ++j) a[i][j] = 0;
    }

    init();

    int mx = -1;
    vector<int> ans(5, 0);
    for (int i = 0; i < n; ++i) {
        int L = i - 1, R = n;
        while (R > L + 1) {
            int M = (L + R) / 2;
            vector<int> q = query(i, M);
            int sum = accumulate(q.begin(), q.end(), 0);
            if (sum <= k) {
                if (M - i + 1 > mx) {
                    mx = M - i + 1;
                    ans = q;
                }
                L = M;
            } else {
                R = M;
            }
        }
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << ' ';
    cout << '\n';
}
