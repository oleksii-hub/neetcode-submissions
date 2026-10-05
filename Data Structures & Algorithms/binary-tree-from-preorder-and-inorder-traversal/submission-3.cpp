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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* node = nullptr;
        TreeNode* root = nullptr;
        std::unordered_map<int, TreeNode*> cache;

        for (std::size_t preIdx = 0, inIdx = 0; preIdx < preorder.size(); ++preIdx)
        {
            if (!root)
            {
                node = new TreeNode(preorder[preIdx]);
                root = node;
                cache[preorder[preIdx]] = node;
                continue;
            }

            while (node->val != inorder[inIdx])
            {
                node->left = new TreeNode(preorder[preIdx]);
                node = node->left;

                cache[preorder[preIdx]] = node;
                ++preIdx;
            }

            while (inIdx < inorder.size())
            {
                auto it = cache.find(inorder[inIdx]);
                if (it == cache.end()) break;

                node = it->second;
                ++inIdx;
            }
            
            if (preIdx == preorder.size())
                break;

            node->right = new TreeNode(preorder[preIdx]);
            node = node->right;
            cache[preorder[preIdx]] = node;
        }

        return root;
    }
};
