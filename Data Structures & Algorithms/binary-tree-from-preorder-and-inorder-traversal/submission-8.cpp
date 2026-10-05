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
    TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        std::array<TreeNode*, 2001> created{};           // value -> node; nullptr = not yet
        const auto slot = [](int v) { return static_cast<std::size_t>(v + 1000); };

        auto* const root = new TreeNode(preorder[0]);
        created[slot(root->val)] = root;

        TreeNode* node = root;
        std::size_t inIdx = 0;

        for (std::size_t preIdx = 1; preIdx < preorder.size(); ++preIdx) {
            auto* const fresh = new TreeNode(preorder[preIdx]);

            if (node->val != inorder[inIdx]) {           // node's left subtree still pending
                node->left = fresh;
            } else {                                     // left done: pass created nodes
                while (TreeNode* passed = created[slot(inorder[inIdx])]) {
                    node = passed;
                    ++inIdx;
                }
                node->right = fresh;
            }

            node = fresh;
            created[slot(fresh->val)] = fresh;
        }
        return root;
    }
};
