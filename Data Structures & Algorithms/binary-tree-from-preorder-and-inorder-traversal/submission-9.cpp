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
        std::array<int, 2001> inPos{};                   // value -> index in inorder
        for (int i = 0; i < std::ssize(inorder); ++i) inPos[slot(inorder[i])] = i;

        std::size_t next = 0;                            // next preorder value to consume
        return build(preorder, inPos, next, 0, static_cast<int>(std::ssize(inorder)));
    }

private:
    static std::size_t slot(int v) { return static_cast<std::size_t>(v + 1000); }

    // Builds the subtree whose inorder range is [lo, hi).
    static TreeNode* build(const std::vector<int>& preorder, const std::array<int, 2001>& inPos,
                           std::size_t& next, int lo, int hi) {
        if (lo >= hi) return nullptr;

        const int val = preorder[next++];                // preorder: root comes first
        const int mid = inPos[slot(val)];                // splits inorder into left | right

        auto* const node = new TreeNode(val);
        node->left  = build(preorder, inPos, next, lo,      mid);   // order matters:
        node->right = build(preorder, inPos, next, mid + 1, hi);    // left consumes first
        return node;
    }
};
