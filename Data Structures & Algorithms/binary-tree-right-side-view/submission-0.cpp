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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;

        std::deque<const TreeNode*> q;
        q.emplace_back(root);
        while(!q.empty())
        {
            for (auto n = q.size(); n > 0; --n)
            {
                const TreeNode* node = q.front();
                q.pop_front();
                if (n == 1)
                    result.emplace_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
        }

        return result;
    }
};
