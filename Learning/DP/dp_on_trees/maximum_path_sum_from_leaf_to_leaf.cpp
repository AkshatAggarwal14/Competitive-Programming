#include <Akshat.hpp>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v = -1) : val(v), left(nullptr), right(nullptr) {}
};

int main() {
    vector<int> val =
        // {10, 2, -10, 20, 1, -25};  // 23
        // {10, 2, -10, 20, -1000, -25};  // 20
        // {35, 2, -10, 20, -1000, -25};  // 22
        {35, 2, -10, 20, -1000, -20};  // 27
    vector<TreeNode> nodes(6);
    for (int i = 0; i < 6; ++i) nodes[i].val = val[i];
    TreeNode* root = &nodes[0];
    root->left = &nodes[1];
    root->right = &nodes[2];
    root->left->left = &nodes[3];
    root->left->right = &nodes[4];
    root->right->right = &nodes[5];

    int res = INT_MIN;
    auto dfs = [&](const auto& self, TreeNode* node) {
        if (node == nullptr) return 0;
        int l = self(self, node->left);
        int r = self(self, node->right);

        int temp;
        if (node->left && node->right)
            temp = node->val + max(l, r);
        else if (node->left)
            temp = node->val + l;
        else if (node->right)
            temp = node->val + r;
        else
            temp = node->val;

        int ans = node->val + l + r;
        res = max(res, ans);
        return temp;
    };
    dfs(dfs, root);
    cout << "Maximum Path Sum between two leaves = " << res << '\n';
}