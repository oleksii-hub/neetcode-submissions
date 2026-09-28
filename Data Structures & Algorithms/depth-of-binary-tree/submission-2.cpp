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
    if (!root) return 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            ++depth;
            for (auto levelSize = q.size(); levelSize > 0; --levelSize) {
                TreeNode* const node = q.front();
                q.pop();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }
};
