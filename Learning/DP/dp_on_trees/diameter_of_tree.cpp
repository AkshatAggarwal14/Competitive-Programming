/*
    ? Introduction
    - Diameter of tree
    ! M1
    - For each node find: Height(Left) + Height(Right) + 1
    - Diameter = Maximum value from all nodes

    ! M2
    - DFS twice, first find farthest node from root, then find farthest node from farthest node.

    ? 3 steps in tree recursive codes
    ? 1. Base condition - Gives answer for Hypothesis.
    ? 2. Hypothesis - Get answer of left and right node.
    ? 3. Induction - Use left and right answer to find root's answer.
*/

#include <Akshat.hpp>
const int INF = INT_MAX;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v = -1) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    // int n = 5;
    // cin >> n;
    vector<TreeNode> nodes(5);
    for (int i = 0; i < 5; ++i) nodes[i].val = i;
    TreeNode* root = &nodes[0];
    root->left = &nodes[1];
    root->right = &nodes[2];
    root->left->left = &nodes[3];
    root->left->right = &nodes[4];

    vector<int> res(5, -1);
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
        //? Base condition
        if (node == nullptr) return 0;
        //? Hypothesis
        int l = dfs(node->left);
        int r = dfs(node->right);
        //? Induction
        // if it is answer, return 1 + l + r
        // if it is not answer, return 1 + max(l, r)
        int temp = 1 + max(l, r);    // return this as this will be used in parent
        res[node->val] = 1 + l + r;  //! Or use a single variable, instead of storing
        return temp;
    };
    dfs(root);
    dbg(res);
    cout << "Diameter of tree = " << *max_element(res.begin(), res.end()) << '\n';
}