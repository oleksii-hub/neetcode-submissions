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
        return checkedHeight(root).has_value();
    }

private:
    // nullopt = subtree is unbalanced; otherwise its height
    static std::optional<int> checkedHeight(const TreeNode* node) {
        if (!node) return 0;

        const auto left = checkedHeight(node->left);
        if (!left) return std::nullopt;

        const auto right = checkedHeight(node->right);
        if (!right) return std::nullopt;

        if (std::abs(*left - *right) > 1) return std::nullopt;
        return 1 + std::max(*left, *right);
    }
};