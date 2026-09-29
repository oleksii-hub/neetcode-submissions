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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (equal(root, subRoot))
            return true;

        if (!root)
            return false;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool equal(TreeNode* p, TreeNode* q)
    {
        if (!p || !q) return p == q;

        return
            p->val == q->val &&
            equal(p->left, q->left) &&
            equal(p->right, q->right);
    }
};
