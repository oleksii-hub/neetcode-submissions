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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        const int target = height(subRoot);
        bool found = false;
        scan(root, subRoot, target, found);
        return found;
    }

private:
    static int height(const TreeNode* n) {
        if (!n) return 0;
        return 1 + std::max(height(n->left), height(n->right));
    }

    // Returns the height of node's subtree; compares only where heights match.
    static int scan(const TreeNode* node, const TreeNode* sub, int target, bool& found) {
        if (!node) return 0;
        const int left  = scan(node->left,  sub, target, found);
        const int right = scan(node->right, sub, target, found);
        const int h = 1 + std::max(left, right);
        if (!found && h == target) found = isSameTree(node, sub);
        return h;
    }

    static bool isSameTree(const TreeNode* p, const TreeNode* q) {
        if (!p || !q) return p == q;
        return p->val == q->val
            && isSameTree(p->left,  q->left)
            && isSameTree(p->right, q->right);
    }
};
