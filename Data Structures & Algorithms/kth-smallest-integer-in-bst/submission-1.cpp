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
    int kthSmallest(TreeNode* root, int k) {
        auto* kthNode = searchBST(root, k);
        return kthNode->val;
    }

    TreeNode* searchBST(TreeNode* node, int& k)
    {
        if (!node) return nullptr;

        if (auto left = searchBST(node->left, k)) {
            return left;
        }

        --k;
        if (k == 0) return node;

        return searchBST(node->right, k);
    }
};
