// https://cses.fi/problemset/task/1749/

#include <bits/stdc++.h>
using namespace std;

/**
 * RQT - Range Query Trie
 * Thanks abbie sir!
 * Walk the trie - Just like walking the segtree
 * Counting indices in cnt integer
 */

const int MIN_CH = '0', LENGTH = 10;

class Trie {
    static const int PADDED_LEN = 9;

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

   public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    string paddedString(int num) const {
        string s = to_string(num);
        return string(PADDED_LEN - s.size(), '0') + s;
    }

    TrieNode *insert(int num) const {
        string s = paddedString(num);
        TrieNode *cur = root;
        for (auto &ch : s) {
            ++cur->cnt;
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        ++cur->cnt;
        return cur;
    }

    TrieNode *erase(int num) const {
        string s = paddedString(num);
        TrieNode *cur = root;
        for (auto &ch : s) {
            --cur->cnt;
            assert(cur->child[ch - MIN_CH] != nullptr);
            cur = cur->child[ch - MIN_CH];
        }
        --cur->cnt;
        return cur;
    }

    // kth smallest number in array
    int kthSmallest(int k) const {
        TrieNode *cur = root;
        int result = 0;

        for (int _ = 0; _ < PADDED_LEN; ++_) {
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    int childSize = cur->child[i]->cnt;
                    if (childSize >= k) {
                        result = 10 * result + i;
                        cur = cur->child[i];
                        break;
                    }
                    k -= childSize;
                }
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;

    Trie trie;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        trie.insert(i);
    }

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        int index = trie.kthSmallest(k);
        cout << a[index] << ' ';
        trie.erase(index);
    }
}