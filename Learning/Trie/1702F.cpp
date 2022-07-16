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
        // add from highest set bit
        // to match prefix when find()
        for (int i = __lg(x); i >= 0; --i) {
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
        for (int i = __lg(x); i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) return;
            cur = cur->bit[b];
            --cur->cnt;
        }
        --cur->end;
        return;
    }

    bool find(int x) {
        TrieNode *cur = root;
        for (int i = __lg(x); i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!cur->bit[b]) return false;
            cur = cur->bit[b];
        }
        return cur->cnt > 0;
    }
};

void test() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    binary_trie trie;
    for (auto &A : a) cin >> A, A >>= __builtin_ctz(A);  // remove trailing zeroes
    for (auto &B : b) cin >> B, B >>= __builtin_ctz(B), trie.insert(B);
    sort(a.rbegin(), a.rend());  // desc order
    for (auto &A : a) {
        if (!trie.find(A)) return void(cout << "NO\n");
        trie.remove(A);
    }
    cout << "YES\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        test();
    }
}