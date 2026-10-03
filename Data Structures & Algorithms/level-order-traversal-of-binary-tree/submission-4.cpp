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
        std::vector<std::vector<int>> levels;
        std::size_t depth = 0;
        walk(root, depth, levels);

        return levels;
    }

private:
    static void walk(TreeNode* node, std::size_t depth, std::vector<std::vector<int>>& levels) {
        if (!node)
            return;

        if (depth == levels.size())
            levels.emplace_back();

        levels[depth].push_back(node->val);
        walk(node->left, depth + 1, levels);
        walk(node->right, depth + 1, levels);
    }
};
