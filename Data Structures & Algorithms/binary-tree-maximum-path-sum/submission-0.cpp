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
    int maxPathSum(TreeNode* root) {
        int best = std::numeric_limits<int>::min();
        down(root, best);

        return best;
    }

private:
    static int down(TreeNode* node, int& best) {
        if (!node)
            return 0;

        int left = std::max(0, down(node->left, best));
        int right = std::max(0, down(node->right, best));

        best = std::max(best, node->val + left + right);
        return node->val + std::max(left, right);
    }
};
