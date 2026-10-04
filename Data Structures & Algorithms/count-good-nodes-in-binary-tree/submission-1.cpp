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
        if (!root) return 0;

        int goodNodes = 0;
        walk(root, root->val, goodNodes);
        return goodNodes;
    }

private:
    static void walk(TreeNode* node, int maxValue, int &goodNodes)
    {
        if (!node) return;

        if (node->val >= maxValue) ++goodNodes;
        maxValue = std::max(maxValue, node->val);
        walk(node->left, maxValue, goodNodes);
        walk(node->right, maxValue, goodNodes);
    }
};
