// https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/

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

    int countLessThan(int k, int x) {
        TrieNode *cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if (!cur) return res;
            int prefBit = (x >> i) & 1, kBit = (k >> i) & 1;
            if (kBit == 0) {
                cur = cur->bit[prefBit];
            } else {
                if (cur->bit[prefBit]) res += cur->bit[prefBit]->cnt;
                cur = cur->bit[1 ^ prefBit];
            }
        }
        return res;
    }

    int countLessEqual(int k, int x) {
        return countLessThan(k + 1, x);
    }
};

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &A : a) cin >> A;

    binary_trie trie;
    // count pairs, considering right value - your current value and left value - any value inside trie
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += trie.countLessEqual(r, a[i]) -
               trie.countLessEqual(l - 1, a[i]);
        trie.insert(a[i]);
    }

    cout << ans << '\n';
}

int32_t main() {
    solve();
}