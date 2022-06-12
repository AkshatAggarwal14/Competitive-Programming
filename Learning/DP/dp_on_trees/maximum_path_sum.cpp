/*
        1
       / \
      2   3
    Max path sum = 1 + 2 + 3 = 6

    What if nodes have -ve values?
*/

#include <Akshat.hpp>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v = -1) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    vector<int> val =
        // {-100, -10, -5, -2, -1};  // -1
        {20, -10, -10, -2, 200};  // 210
    // {1, -10, -10, -2, 200};  // 200
    // {1, 100, -10, -2, 2};  // 103
    vector<TreeNode> nodes(5);
    for (int i = 0; i < 5; ++i) nodes[i].val = val[i];
    TreeNode* root = &nodes[0];
    root->left = &nodes[1];
    root->right = &nodes[2];
    root->left->left = &nodes[3];
    root->left->right = &nodes[4];

    int res = INT_MIN;
    auto dfs = [&](const auto& self, TreeNode* node) {
        if (node == nullptr) return 0;
        int l = self(self, node->left);
        int r = self(self, node->right);
        // if it is answer, return l + r + node->val
        // if it is not answer, return max(l, r) + node->val
        int temp = node->val + max(max(l, r), 0);  // as value might be negative
        int ans = max(temp, node->val + l + r);    //! max(temp, *) is important
        res = max(res, ans);
        return temp;
    };
    dfs(dfs, root);
    cout << "Maximum Path Sum = " << res << '\n';
}