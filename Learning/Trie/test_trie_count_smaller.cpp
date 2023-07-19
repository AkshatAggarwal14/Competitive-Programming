// Solution to https://www.spoj.com/problems/MKTHNUM/
#include <bits/stdc++.h>
using namespace std;

/**
 * RQT - Range Query Trie
 * Thanks abbie sir!
 */

#include <debug.hpp>

const int MIN_CH = '0', LENGTH = 10;

string paddedString(int num, int len) {
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

    TrieNode *root;

   public:
    Trie() {
        root = new TrieNode();
    }

    TrieNode *insert(int num) {
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

    TrieNode *erase(int num) {
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

    bool find(int num) {
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
    int countSmaller(int num) {
        string s = paddedString(num, PADDED_LEN);
        TrieNode *cur = root;
        int count = 0;

        for (int level = 0; level < PADDED_LEN; ++level) {
            bool done = false;
            for (int i = 0; i < LENGTH; ++i) {
                if (cur->child[i]) {
                    int childCount = cur->child[i]->cnt;

                    cout << i << ' ' << s[level] << ' ' << childCount << '\n';

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

    int countBetween(int L, int R) {
        if (L > R) return 0;
        return countSmaller(R + 1) - countSmaller(L);
    }
};

int main() {
    Trie<2> trie;
    trie.insert(8);
    trie.insert(9);

    // cout << trie.countSmaller(8) << '\n';
    // cout << trie.countSmaller(9) << '\n';
    // cout << trie.countSmaller(10) << '\n';
    cout << trie.countSmaller(11) << '\n';
    // cout << trie.countSmaller(12) << '\n';

    return 0;
}

/*
13 1
51 -23 35 -93 -59 -84 -59 -73 -87 33 -77 20 -26
5 10 3

13 1
51 77 35 7 42 16 42 27 13 33 23 20 74
5 10 3
*/