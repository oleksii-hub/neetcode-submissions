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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::size_t currentDepth = 0;
        walk(root, currentDepth, result);

        return result;
    }

private:
    static void walk(TreeNode* node, std::size_t currentDepth, std::vector<std::vector<int>>& result) {
        if (!node)
            return;

        if (currentDepth == result.size())
            result.emplace_back();

        result[currentDepth].push_back(node->val);

        walk(node->left, currentDepth + 1, result);
        walk(node->right, currentDepth + 1, result);
    }
};
