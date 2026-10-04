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
    bool isValidBST(TreeNode* root) {
        return isValidSubTree(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

    bool isValidSubTree(TreeNode* node, int min, int max)
    {
        if (!node) return true;

        if (node->val <= min || node->val >= max)
            return false;

        return isValidSubTree(node->left, min, std::min(max, node->val))
            && isValidSubTree(node->right, std::max(min, node->val), max);
    }
};
