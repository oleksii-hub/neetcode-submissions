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
    int goodNodes(TreeNode* root) {
        struct Frame {
            const TreeNode* node;
            int pathMax;   // max value on the path above node
        };

        std::vector<Frame> pending;
        if (root) pending.push_back({root, std::numeric_limits<int>::min()});

        int good = 0;
        while (!pending.empty()) {
            const auto [node, pathMax] = pending.back();   // copy, not reference
            pending.pop_back();

            if (node->val >= pathMax) ++good;
            const int nextMax = std::max(pathMax, node->val);

            if (node->left)  pending.push_back({node->left,  nextMax});
            if (node->right) pending.push_back({node->right, nextMax});
        }
        return good;
    }
};
