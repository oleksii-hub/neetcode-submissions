/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        height(root, isBalanced);
        return isBalanced;
    }

    int height(TreeNode* node, bool& isBalanced)
    {
        if (!node)
            return 0;

        int leftH = height(node->left, isBalanced);
        int rightH = height(node->right, isBalanced);
        if (std::abs(leftH - rightH) > 1)
            isBalanced = false;

        return 1 + std::max(leftH, rightH);
    }
};
