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
    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        height(root, best);
        return best;
    }

private:
    static int height(const TreeNode* node, int& best) {
        if (!node) return 0;
        const int left  = height(node->left, best);
        const int right = height(node->right, best);
        best = std::max(best, left + right);   // path with apex at node
        return 1 + std::max(left, right);      // one-armed path, for the parent
    }
};
