// Solution to https://www.hackerearth.com/challenges/competitive/dsa-coding-contest-june-23/algorithm/endless-integer-sequence-088184af/
// Problem by `theabbie`.

#include <bits/stdc++.h>
using namespace std;

/**
 * RQT - Range Query Trie
 * Thanks abbie sir!
 * Walk the trie - Just like walking the segtree
 * Storing indices in position vector
 */

const int MIN_CH = '0', LENGTH = 10;

class Trie {
    static const int PADDED_LEN = 11;

    class TrieNode {
       public:
        array<TrieNode *, LENGTH> child;
        unordered_map<long long, int> deleted;

        TrieNode() {
            for (int i = 0; i < LENGTH; ++i)
                child[i] = nullptr;
        }
    };

    TrieNode *root;

   public:
    Trie() {
        root = new TrieNode();
    }

    string paddedString(long long num) {
        string s = to_string(num);
        return string(PADDED_LEN - s.size(), '0') + s;
    }

    TrieNode *insert(long long num) {
        string s = paddedString(num);
        TrieNode *cur = root;
        for (auto &ch : s) {
            ++cur->deleted[num];
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        ++cur->deleted[num];
        return cur;
    }

    TrieNode *erase(long long num) {
        string s = paddedString(num);
        TrieNode *cur = root;
        for (auto &ch : s) {
            --cur->deleted[num];
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        --cur->deleted[num];
        return cur;
    }

    // kth smallest number in array
    long long kthSmallest(long long k) {
        TrieNode *cur = root;
        long long result = 0, total = stoll('1' + string(PADDED_LEN - 1, '0'));

        for (int _ = 0; _ < PADDED_LEN; ++_) {
            for (int i = 0; i < LENGTH; ++i) {
                if (!cur->child[i]) cur->child[i] = new TrieNode();
                TrieNode *childNode = cur->child[i];
                long long childSize = total - childNode->deleted.size();
                if (childSize >= k) {
                    result = 10 * result + i;
                    cur = childNode;
                    break;
                }
                k -= childSize;
            }
            total /= 10;
        }

        return result;
    }

    long long MEX() {
        return kthSmallest(1LL);
    }
};

int main() {
    Trie trie;
    int q;
    cin >> q;

    while (q--) {
        int type;
        long long k;
        cin >> type >> k;
        if (type == 1) {
            trie.insert(k - 1);
        } else {
            cout << trie.kthSmallest(k) + 1 << '\n';
        }
    }
}

/**
6
2 101
1 1
2 1
1 2
2 1
2 101

*/