// Solution to https://www.spoj.com/problems/MKTHNUM/
#include <bits/stdc++.h>
using namespace std;

/**
 * RQT - Range Query Trie
 * Thanks abbie sir!
 * Walk the trie - Just like walking the segtree
 * Storing indices in position vector
 */

const int MIN_CH = '0', LENGTH = 10;
const int OFFSET = 1e9;

class Trie {
    static const int PADDED_LEN = 10;

    class TrieNode {
       public:
        array<TrieNode *, LENGTH> child;
        vector<int> pos;

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

    string paddedString(int num) {
        string s = to_string(num);
        return string(PADDED_LEN - s.size(), '0') + s;
    }

    TrieNode *insert(int num, int index) {
        string s = paddedString(num);
        TrieNode *cur = root;
        for (auto &ch : s) {
            cur->pos.push_back(index);
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        cur->pos.push_back(index);
        return cur;
    }

    // kth smallest number in array
    int kthSmallest(int k) {
        assert((k > 0 && k <= int(root->pos.size())));

        TrieNode *cur = root;
        int result = 0;

        for (int _ = 0; _ < PADDED_LEN; ++_) {
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    int childSize = int(cur->child[i]->pos.size());
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

    // kth smallest number in [l, r]
    int kthSmallest(int k, int l, int r) {
        // Queried k is greater than number of elements in trie in [l, r]
        assert((k > 0 && k <= (r - l + 1)));

        TrieNode *cur = root;
        int result = 0;

        for (int _ = 0; _ < PADDED_LEN; ++_) {
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    auto &pos = cur->child[i]->pos;
                    // assumes pos is sorted
                    int childSize = int(distance(lower_bound(pos.begin(), pos.end(), l),
                                                 upper_bound(pos.begin(), pos.end(), r)));
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

    // count numbers smaller than num in [l, r]
    int countSmaller(int num, int l, int r) {
        string s = paddedString(num);
        TrieNode *cur = root;
        int count = 0;

        for (int level = 0; level < PADDED_LEN; ++level) {
            bool done = false;
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    auto &pos = cur->child[i]->pos;
                    // assumes pos is sorted
                    int childCount = int(distance(lower_bound(pos.begin(), pos.end(), l),
                                                  upper_bound(pos.begin(), pos.end(), r)));

                    if (i < s[level] - MIN_CH) {
                        count += childCount;
                    } else if (i == s[level] - MIN_CH) {
                        cur = cur->child[i];
                        done = true;
                        break;
                    } else {
                        return count;
                    }
                }
            }
            // if doesnt move to lower level just break
            if (!done) break;
        }

        return count;
    }
};

int main() {
    Trie trie;

    int n, q;
    cin >> n >> q;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        trie.insert(num + OFFSET, i);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k, --l, --r;
        int result = trie.kthSmallest(k, l, r) - OFFSET;
        cout << result << '\n';
    }

    return 0;
}
