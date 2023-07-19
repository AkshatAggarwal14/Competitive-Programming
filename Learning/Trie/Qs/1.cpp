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

// Find MAX(a[l]^a[l+1]^...^a[r]) = MAX(pref[r]^pref[l-1])
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = 0, pref = 0;
    binary_trie trie;
    trie.insert(0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref ^= a[i];
        ans = max(ans, trie.get_xor(pref));
        trie.insert(pref);
    }

    cout << ans << '\n';
}