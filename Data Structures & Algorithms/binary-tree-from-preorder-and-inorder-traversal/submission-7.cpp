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
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* node = root;
        std::unordered_map<int, TreeNode*> cache;
        cache[preorder[0]] = node;

        for (std::size_t preIdx = 1, inIdx = 0; preIdx < preorder.size(); ++preIdx)
        {
            int val = preorder[preIdx];

            if (node->val != inorder[inIdx])
            {
                node->left = new TreeNode(val);
                node = node->left;
            }
            else
            {
                while (inIdx < inorder.size())
                {
                    auto it = cache.find(inorder[inIdx]);
                    if (it == cache.end()) break;

                    node = it->second;
                    ++inIdx;
                }
                
                node->right = new TreeNode(val);
                node = node->right;
            }

            cache[val] = node;
        }

        return root;
    }
};
