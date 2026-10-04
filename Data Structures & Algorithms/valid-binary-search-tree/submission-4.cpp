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
        if (!root) return true;

        struct Frame
        {
            const TreeNode* node;
            std::pair<int, int> interval;
        };

        std::queue<Frame> q;
        if (root) q.push({root, std::make_pair(std::numeric_limits<int>::min(), std::numeric_limits<int>::max())});
        while (!q.empty())
        {
            for (auto n = q.size(); n > 0; --n)
            {
                auto [node, interval] = q.front();
                q.pop();
                if (node->val <= interval.first || node->val >= interval.second)
                    return false;

                if (node->left) q.push({node->left, std::make_pair(interval.first, std::min(interval.second, node->val))});
                if (node->right) q.push({node->right, std::make_pair(std::max(interval.first, node->val), interval.second)});
            }
        }

        return true;
    }
};
