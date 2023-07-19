#include <bits/stdc++.h>
using namespace std;

template <char MIN_CHAR = 'a', int ALPHABET = 26>
class Trie {
    class TrieNode {
       public:
        array<TrieNode *, ALPHABET> child;
        int cnt, end;

        TrieNode() {
            for (int i = 0; i < ALPHABET; ++i)
                child[i] = nullptr;
        }
    };

    TrieNode *root;

   public:
    Trie() {
        root = new TrieNode();
    }

    TrieNode *insert(const string &word) {
        TrieNode *cur = root;
        for (auto &ch : word) {
            ++cur->cnt;

            if (!cur->child[ch - MIN_CHAR]) {
                cur->child[ch - MIN_CHAR] = new TrieNode();
            }
            cur = cur->child[ch - MIN_CHAR];
        }
        ++cur->cnt, ++cur->end;
        return cur;
    }

    TrieNode *erase(const string &word) {
        TrieNode *cur = root;
        for (auto &ch : word) {
            --cur->cnt;
            if (!cur->child[ch - MIN_CHAR]) {
                return nullptr;
            }
            cur = cur->child[ch - MIN_CHAR];
        }
        --cur->cnt, --cur->end;
        return cur;
    }

    TrieNode *find(const string &word) const {
        TrieNode *cur = root;

        for (auto &ch : word) {
            cur = cur->child[ch - MIN_CHAR];
            if (!cur) break;
        }

        return cur;
    }

    // count words which are prefixes of "word"
    int count_prefixes(const string &word) {
        TrieNode *cur = root;
        int count = 0;

        for (auto &ch : word) {
            count += cur->end;  // count empty too
            cur = cur->child[ch - MIN_CHAR];
            if (!cur) break;
        }

        // count matching also
        count += cur->end;

        return count;
    }

    int count_starting_with(const string &word) {
        TrieNode *cur = find(word);
        if (!cur) return 0;

        return cur->cnt;
    }
};

int main() {
    Trie tr;
    tr.insert("hello");
    tr.insert("help");
    cout << tr.find("help") << '\n';
    cout << tr.count_starting_with("hel") << '\n';
    cout << tr.find("hel") << '\n';
    if (tr.erase("huh") == nullptr) {
        cout << "Erase works?\n";
    }
    if (tr.find("huh") == nullptr) {
        cout << "find words too!\n";
    }
    cout << tr.find("hello") << '\n';
    cout << tr.find("hellol");
}
