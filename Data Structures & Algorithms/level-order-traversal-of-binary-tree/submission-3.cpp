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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> levels;
        if (!root)
            return levels;

        std::queue<const TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto& level = levels.emplace_back();
            level.reserve(q.size());
            for (std::size_t i = q.size(); i > 0; --i)
            {
                const TreeNode* node = q.front();
                q.pop();
                level.emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return levels;
    }
};
