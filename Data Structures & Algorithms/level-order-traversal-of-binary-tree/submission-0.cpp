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
        int currentHeight = 0;
        walk(root, currentHeight, result);

        return result;
    }

    void walk(TreeNode* node, int currentHeight, std::vector<std::vector<int>>& result) {
        if (!node)
            return;

        if (currentHeight == result.size())
            result.push_back({});

        result[currentHeight].push_back(node->val);

        walk(node->left, currentHeight + 1, result);
        walk(node->right, currentHeight + 1, result);
    }
};
