// https://www.codechef.com/problems/SUBBXOR
// https://www.spoj.com/problems/SUBXOR/

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

    // Count subarrays such that (pref XOR (values in trie) < k)
    int countLessThan(int k, int pref) {
        TrieNode *cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if (!cur) return res;
            int prefBit = (pref >> i) & 1, kBit = (k >> i) & 1;
            if (kBit == 0) {
                // then the bit must be made equal to prefBit to obtain 0 XOR
                cur = cur->bit[prefBit];
            } else {
                // if 1, then we can add all which makes the XOR 0 -> prefBit ^ prefBit
                if (cur->bit[prefBit]) res += cur->bit[prefBit]->cnt;
                // we can then move to 1
                cur = cur->bit[1 ^ prefBit];
            }
        }
        return res;
    }
};

// Count(A[l]^...A[r]) <= K
// Count(pref[l-1]^pref[r]) <= K
// Count subarrays such that (pref XOR values in trie < K)
// we somehow count how many of these (numbers in trie) are such that its xor with xor[1:i] is smaller than k
// subarrays ending at i with xor[j, i] <= k

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    binary_trie trie;
    long long ans = 0;
    int pref = 0;
    trie.insert(0);

    for (int i = 0; i < n; ++i) {
        pref ^= a[i];
        int increase = trie.countLessThan(k, pref);
        ans += increase;
        trie.insert(pref);
    }

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}