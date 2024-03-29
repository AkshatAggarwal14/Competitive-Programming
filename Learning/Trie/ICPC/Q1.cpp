#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TrieNode {
    TrieNode *bit[2];
    int cnt, end;
    TrieNode() {
        cnt = end = 0;
        bit[0] = bit[1] = nullptr;
    }

    ~TrieNode() {
        delete bit[0];
        delete bit[1];
    }
};

struct binary_trie {
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

    void remove(int x) {
        TrieNode *cur = root;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;

            if (cur->bit[b]->cnt > 0) {
                --cur->bit[b]->cnt;
            }
            if (cur->bit[b]->cnt == 0) return;
            cur = cur->bit[b];
            --cur->cnt;
        }
        --cur->end;
    }

    int countLessThan(ll k, int x) {
        TrieNode *cur = root;
        int res = 0;
        for (int i = 31; i >= 0; --i) {
            if (!cur) return res;
            int prefBit = (x >> i) & 1, kBit = (k >> i) & 1;
            if (kBit == 0) {
                // find number with same bit set, so XOR will be zero
                cur = cur->bit[prefBit];
            } else {
                // find number with same bit set, and add count for which XOR will be zero
                if (cur->bit[prefBit]) res += cur->bit[prefBit]->cnt;
                // go to other way for next bit
                cur = cur->bit[1 ^ prefBit];
            }
        }
        return res;
    }

    ~binary_trie() {
        delete root;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        binary_trie trie;
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        auto can = [&](ll value) {
            for (int i = 0; i < n; ++i) {
                trie.remove(a[i]);
            }
            ll count = 0;
            for (int i = 0; i < n; ++i) {
                count += trie.countLessThan(value + 1, a[i]);
                trie.insert(a[i]);
            }
            return count;
        };

        ll L = 0, R = 3e9;
        ll ans = 0;
        // --L, ++R;
        while (R >= L) {
            ll M = (L + R) / 2;
            if (can(M) >= k) {
                R = M - 1;
                ans = M;
            } else {
                L = M + 1;
            }
        }

        cout << ans << '\n';
    }
}