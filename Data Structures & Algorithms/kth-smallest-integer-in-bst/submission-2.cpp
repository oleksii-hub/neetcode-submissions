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
        std::vector<const TreeNode*> st;
        const TreeNode* node = root;

        while (node || !st.empty())
        {
            while(node)
            {
                st.push_back(node);
                node = node->left;
            }

            node = st.back();
            st.pop_back();

            --k;
            if (k == 0) return node->val;

            node = node->right;
        }

        return -1;
    }
};
