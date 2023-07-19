#include <bits/stdc++.h>
using namespace std;

template <char MIN_CHAR = 'a', int ALPHABET = 26>
struct trie {
    struct trieNode {
        array<int, ALPHABET> child;
        int cnt, end;

        trieNode() {
            cnt = end = 0;
            memset(&child[0], -1, ALPHABET * sizeof(int));
        }
    };

    static const int ROOT = 0;

    vector<trieNode> nodes = {trieNode()};

    int newChild() {
        int childIndex = int(nodes.size());
        nodes.emplace_back();
        return childIndex;
    }

    int insert(const string &word) {
        int cur = ROOT;

        for (auto &ch : word) {
            nodes[cur].cnt++;

            int childIndex = ch - MIN_CHAR;
            // if doesnt exist, make new child
            if (nodes[cur].child[childIndex] < 0) {
                nodes[cur].child[childIndex] = newChild();
            }

            cur = nodes[cur].child[childIndex];
        }

        nodes[cur].cnt++, nodes[cur].end++;
        return cur;
    }

    int erase(const string &word) {
        int cur = ROOT;

        for (auto &ch : word) {
            nodes[cur].cnt--;

            int childIndex = ch - MIN_CHAR;
            // if doesnt exist, error
            if (nodes[cur].child[childIndex] < 0) {
                throw runtime_error("The child doesnt exist.");
            }

            cur = nodes[cur].child[childIndex];
        }

        nodes[cur].cnt--, nodes[cur].end--;
        return cur;
    }

    int find(const string &str) const {
        int cur = ROOT;

        for (char ch : str) {
            cur = nodes[cur].child[ch - MIN_CHAR];

            if (cur < 0)
                break;
        }

        return nodes[cur].end > 0 ? cur : -1;
    }

    // Given a string, how many words in the trie are prefixes of the string?
    int count_prefixes(const string &str, bool include_full = true) const {
        int cur = ROOT, count = 0;

        for (char ch : str) {
            count += nodes[cur].end;
            cur = nodes[cur].child[ch - MIN_CHAR];

            if (cur < 0)
                break;
        }

        if (include_full && cur >= 0)
            count += nodes[cur].end;

        return count;
    }

    // Given a string, how many words in the trie start with the given string?
    int count_starting_with(const string &str, bool include_full = true) const {
        int cur = find(str);
        if (cur < 0) return 0;
        return nodes[cur].cnt - (include_full ? 0 : nodes[cur].end);
    }
};

int main() {
    trie tr;
    tr.insert("hello");
    tr.insert("help");
    cout << tr.find("help") << '\n';
    cout << tr.count_starting_with("hel") << '\n';
    cout << tr.find("hel") << '\n';
}
