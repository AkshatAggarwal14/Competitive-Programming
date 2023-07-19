#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif
using ll = long long;

const ll INF = 1e18;
const ll N = 1e5 + 5;
const ll MOD = 1e9 + 7;  // 998244353;

const int LENGTH = 10;

vector<int> getInv(const vector<int> &p) {
    int m = int(p.size());
    vector<pair<int, int>> s(m);
    for (int i = 0; i < m; ++i) {
        s[i] = {p[i], i};
    }
    sort(s.begin(), s.end());
    vector<int> res(m);
    for (int i = 0; i < m; ++i) res[i] = s[i].second;
    return res;
}

class Trie {
    class TrieNode {
       public:
        array<TrieNode *, LENGTH> child;
        int cnt;

        TrieNode() {
            cnt = 0;
            for (int i = 0; i < LENGTH; ++i)
                child[i] = nullptr;
        }
    };

    TrieNode *root;

   public:
    Trie() {
        root = new TrieNode();
    }

    TrieNode *insert(const vector<int> &p) {
        TrieNode *cur = root;
        for (auto &ch : p) {
            ++cur->cnt;
            if (!cur->child[ch]) {
                cur->child[ch] = new TrieNode();
            }
            cur = cur->child[ch];
        }
        ++cur->cnt;
        return cur;
    }

    int getMaxMatching(const vector<int> &p) {
        auto inv = getInv(p);
        dbg(p, inv);
        int res = 0;
        TrieNode *cur = root;
        for (auto &ch : inv) {
            if (!cur->child[ch]) {
                return res;
            }
            ++res;
            cur = cur->child[ch];
        }
        return res;
    }
};

void test() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n, vector<int>(m));

    Trie trie;

    // Inserted all Inverses and found inverses as r = p * q; r_j = q_p_j <- this opposite order requires inverses.

    for (auto &row : p) {
        for (auto &x : row) {
            cin >> x, --x;
        }
        trie.insert(getInv(row));
    }

    for (auto &row : p) {
        cout << trie.getMaxMatching(getInv(row)) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        test();
    }
    return 0;
}
