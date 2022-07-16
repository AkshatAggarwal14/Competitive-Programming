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
        // reverse number in binary for due to max queries
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

    void remove(int x) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) return;  // word doesnt exist
            if (cur->bit[b]->cnt == 1) {
                cur->bit[b] = nullptr;
                return;
            }
            cur = cur->bit[b];
            --cur->cnt;
        }
        --cur->end;
    }

    bool find(int x) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) return false;
            cur = cur->bit[b];
        }
        return cur->cnt > 0;
    }

    // if max is true we get max xor, else we get min xor
    int get_xor(int x, bool max = true) {
        TrieNode *cur = root;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (max) {
                if (cur->bit[b ^ 1]) {  // if opposite set
                    ans |= (1 << i);
                    cur = cur->bit[b ^ 1];
                } else if (cur->bit[b]) {
                    cur = cur->bit[b];
                }
            } else {
                if (cur->bit[b]) {  // if same set
                    cur = cur->bit[b];
                } else if (cur->bit[b ^ 1]) {
                    ans |= (1 << i);
                    cur = cur->bit[b ^ 1];
                }
            }
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    return 0;
}
