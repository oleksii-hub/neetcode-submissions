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
    int goodNodes(TreeNode* root) {
        return count(root, std::numeric_limits<int>::min());
    }

private:
    static int count(const TreeNode* node, int pathMax) {
        if (!node) return 0;
        const int nextMax = std::max(pathMax, node->val);
        return (node->val >= pathMax ? 1 : 0)
            + count(node->left,  nextMax)
            + count(node->right, nextMax);
    }
};
