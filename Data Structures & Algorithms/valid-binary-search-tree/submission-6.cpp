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
    bool isValidBST(TreeNode* root) {
        std::vector<const TreeNode*> st;
        const TreeNode* prev = nullptr;
        const TreeNode* node = root;

        while (node || !st.empty()) {
            while (node) {
                st.push_back(node);
                node = node->left;
            }
            node = st.back();
            st.pop_back();

            if (prev && node->val <= prev->val) return false;
            prev = node;
            node = node->right;
        }

        return true;
    }
};
