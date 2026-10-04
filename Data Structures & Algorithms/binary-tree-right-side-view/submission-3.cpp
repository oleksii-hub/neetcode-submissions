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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        walk(root, 0, result);

        return result;
    }

    static void walk(const TreeNode* node, std::size_t depth, std::vector<int>& out) {
        if (!node) return;
        if (depth == out.size()) out.push_back(node->val);
        walk(node->right, depth + 1, out);
        walk(node->left,  depth + 1, out);
    }
};
