// https://thejoboverflow.com/problem/347/

#include <bits/stdc++.h>
using namespace std;

struct binary_trie {
    struct TrieNode {
        TrieNode *bit[2];
        int cnt, end;
        TrieNode() {
            cnt = end = 0;
            bit[0] = bit[1] = nullptr;
        }
    };

    TrieNode *root = new TrieNode();
    void insert(int x) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) {
                cur->bit[b] = new TrieNode();
            }
            cur = cur->bit[b];
            ++cur->cnt;
        }
        ++cur->end;
    }

    int countLessThan(int k, int pref) {
        TrieNode *cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if (!cur) return res;
            int prefBit = (pref >> i) & 1, kBit = (k >> i) & 1;
            if (kBit == 0) {
                cur = cur->bit[prefBit];
            } else {
                if (cur->bit[prefBit]) res += cur->bit[prefBit]->cnt;
                cur = cur->bit[1 ^ prefBit];
            }
        }
        return res;
    }
};

// Find minimum K for which (count of subarrays with XOR <= K) >= X
// As K increases this count must increase as it includes count of smaller elements than current K, So we can BS on K
void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &A : a) cin >> A;

    auto can = [&](int k) {
        binary_trie trie;
        long long ans = 0;
        int pref = 0;
        trie.insert(0);

        for (int i = 0; i < n; ++i) {
            pref ^= a[i];
            int increase = trie.countLessThan(k + 1, pref);
            ans += increase;
            trie.insert(pref);
        }

        return ans;
    };

    int L = -1, R = (1LL << 21);
    while (R > L + 1) {
        int M = (L + R) / 2;

        if (can(M) >= x) {
            R = M;
        } else {
            L = M;
        }
    }

    cout << R << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}