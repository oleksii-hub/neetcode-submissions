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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        depth = getDepth(root, depth);

        return depth;
    }

    int getDepth(TreeNode* root, int currentDepth)
    {
        if (!root)
            return currentDepth;

        ++currentDepth;
        int leftD = getDepth(root->left, currentDepth);
        int rightD = getDepth(root->right, currentDepth);

        return leftD > rightD ? leftD : rightD;
    }
};
