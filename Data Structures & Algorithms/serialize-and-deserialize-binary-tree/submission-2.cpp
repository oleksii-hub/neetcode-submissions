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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string result;
        writeDFS(root, result);

        return result;
    }

    void writeDFS(TreeNode* node, std::string& str) {
        if (!node)
        {
            str += "n,";
            return;
        }

        char buf[std::numeric_limits<int>::digits10 + 3];
        const auto [end, ec] = std::to_chars(buf, buf + sizeof(buf), node->val);
        str.append(buf, end);
        str += ',';

        writeDFS(node->left, str);
        writeDFS(node->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::string_view in = data.data();
        return readDFS(in);
    }

    TreeNode* readDFS(std::string_view& data)
    {
        const auto token = nextToken(data);
        if (token.empty() || token == "n") return nullptr;

        int val{};
        std::from_chars(token.data(), token.data() + token.size(), val);

        auto* node = new TreeNode(val);
        node->left = readDFS(data);
        node->right = readDFS(data);

        return node;
    }

    static std::string_view nextToken(std::string_view& in) {
        const auto pos = in.find(',');
        const auto token = in.substr(0, pos);
        in.remove_prefix(pos == std::string_view::npos ? in.size() : pos + 1);
        return token;
    }
};
