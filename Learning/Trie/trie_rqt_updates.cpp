// Solution to https://www.spoj.com/problems/MKTHNUM/
#include <bits/stdc++.h>
using namespace std;

/**
 * RQT - Range Query Trie
 * Thanks abbie sir!
 * Walk the trie - Just like walking the segtree
 * Storing indices in position trie
 */

const int MIN_CH = '0', LENGTH = 10;

string paddedString(const int &num, const int &len) {
    string s = to_string(num);
    return string(len - s.size(), '0') + s;
}

// padded length for indices stored
template <int PADDED_LEN = 6>
class Trie {
    class TrieNode {
       public:
        array<TrieNode *, LENGTH> child;
        int cnt;  // stores children count in subtrie
        int end;

        TrieNode() {
            cnt = end = 0;
            for (int i = 0; i < LENGTH; ++i)
                child[i] = nullptr;
        }
    };

   public:
    TrieNode *root;

    Trie() {
        root = new TrieNode();
    }

    TrieNode *insert(int num) const {
        string s = paddedString(num, PADDED_LEN);
        TrieNode *cur = root;
        for (auto &ch : s) {
            ++cur->cnt;
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        ++cur->cnt;
        ++cur->end;
        return cur;
    }

    TrieNode *erase(int num) const {
        string s = paddedString(num, PADDED_LEN);
        TrieNode *cur = root;
        for (auto &ch : s) {
            --cur->cnt;
            if (!cur->child[ch - MIN_CH]) {
                return nullptr;
            }
            cur = cur->child[ch - MIN_CH];
        }
        --cur->cnt;
        --cur->end;
        return cur;
    }

    bool find(int num) const {
        string s = paddedString(num, PADDED_LEN);
        TrieNode *cur = root;
        for (auto &ch : s) {
            if (!cur->child[ch - MIN_CH]) {
                return false;
            }
            cur = cur->child[ch - MIN_CH];
        }
        return cur && cur->end > 0;
    }

    // count numbers smaller than num in trie
    int countSmaller(int num) const {
        string s = paddedString(num, PADDED_LEN);
        TrieNode *cur = root;
        int count = 0;

        for (int level = 0; level < PADDED_LEN; ++level) {
            bool done = false;
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    int childCount = cur->child[i]->cnt;

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

    int countBetween(int L, int R) const {
        if (L > R) return 0;
        return countSmaller(R + 1) - countSmaller(L);
    }
};

template <int PADDED_LEN = 10>
class RQT {
    class RQTNode {
       public:
        array<RQTNode *, LENGTH> child;
        Trie<6> pos;

        RQTNode() {
            for (int i = 0; i < LENGTH; ++i)
                child[i] = nullptr;
        }
    };

   public:
    RQTNode *root;

    RQT() {
        root = new RQTNode();
    }

    RQTNode *insert(int num, int index) const {
        string s = paddedString(num, PADDED_LEN);
        RQTNode *cur = root;
        for (auto &ch : s) {
            cur->pos.insert(index);
            if (!cur->child[ch - MIN_CH]) {
                cur->child[ch - MIN_CH] = new RQTNode();
            }
            cur = cur->child[ch - MIN_CH];
        }
        cur->pos.insert(index);
        return cur;
    }

    bool find(int num, int index) const {
        string s = paddedString(num, PADDED_LEN);
        RQTNode *cur = root;
        for (auto &ch : s) {
            if (!cur->pos.find(index)) return false;
            if (!cur->child[ch - MIN_CH]) return false;
            cur = cur->child[ch - MIN_CH];
        }
        if (!cur->pos.find(index)) return false;
        return true;
    }

    RQTNode *erase(int num, int index) const {
        if (!find(num, index)) return nullptr;
        string s = paddedString(num, PADDED_LEN);
        RQTNode *cur = root;
        for (auto &ch : s) {
            cur->pos.erase(index);
            cur = cur->child[ch - MIN_CH];
        }
        cur->pos.erase(index);
        return cur;
    }

    RQTNode *update(int oldValue, int newValue, int index) const {
        RQTNode *isErased = erase(oldValue, index);
        // oldValue doesnt exist
        if (!isErased) return nullptr;
        return insert(newValue, index);
    }

    // kth smallest number in [l, r]
    int kthSmallest(int k, int l, int r) const {
        // Queried k is greater than number of elements in trie in [l, r]
        assert((k > 0 && k <= (r - l + 1)));

        RQTNode *cur = root;
        int result = 0;

        for (int _ = 0; _ < PADDED_LEN; ++_) {
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    auto &pos = cur->child[i]->pos;

                    int childSize = pos.countBetween(l, r);

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
        string s = paddedString(num, PADDED_LEN);
        RQTNode *cur = root;
        int count = 0;

        for (int level = 0; level < PADDED_LEN; ++level) {
            bool done = false;
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    auto &pos = cur->child[i]->pos;
                    // assumes pos is sorted
                    int childCount = pos.countBetween(l, r);

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

const int OFFSET = 1e9;

int main() {
    RQT<10> rqt;

    int n, q;
    cin >> n >> q;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        rqt.insert(num + OFFSET, i);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k, --l, --r;
        int result = rqt.kthSmallest(k, l, r) - OFFSET;
        cout << result << '\n';
    }
    return 0;
}

/*
13 1
51 -23 35 -93 -59 -84 -59 -73 -87 33 -77 20 -26
5 10 3

13 1
51 77 35 7 42 16 42 27 13 33 23 20 74
5 10 3

14 1
-98 94 -78 -25 95 -35 81 -21 71 75 -65 13 -56 -84
6 11 5

14 1
002 194 022 075 195 065 181 079 171 175 035 113 044 016
6 11 5
*/