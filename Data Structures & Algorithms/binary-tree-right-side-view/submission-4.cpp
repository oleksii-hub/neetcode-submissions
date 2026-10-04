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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> view;
        std::vector<const TreeNode*> level;
        std::vector<const TreeNode*> next;
        if (root) level.push_back(root);

        while (!level.empty()) {
            view.push_back(level.back()->val);   // rightmost node of this level

            next.clear();
            for (const TreeNode* node : level) {
                if (node->left)  next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            std::swap(level, next);
        }
        return view;
    }
};
