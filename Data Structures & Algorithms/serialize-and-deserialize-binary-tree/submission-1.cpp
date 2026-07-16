
class Codec {
public:

    string serialize(TreeNode* root)
    {
        if (root == nullptr) {
            return "[null]";
        }

        if (root->left == nullptr && root->right == nullptr) {
            return "[" + to_string(root->val) + "]";
        }

        stringstream oss;
        oss << '[';
        oss << to_string(root->val);

        auto queue = std::queue<TreeNode*>{};
        queue.push(root->left);
        queue.push(root->right);

        while (not queue.empty())
        {
            auto node = queue.front();
            queue.pop();

            if (node == nullptr) {
                oss << ",null";
                continue;
            }

            oss << ',' << to_string(node->val);
            queue.push(node->left);
            queue.push(node->right);
        }

        oss << ']';
        auto const result = oss.str();

        cout << result << "\n";
        return result;
    }

    TreeNode* deserialize(string data)
    {
        if (data.size() < 2 || data[0] != '[' || data[data.size()-1] != ']') {
            return nullptr;
        }

        size_t index = 1;

        // TODO: this is begging to be an iterator
        // if we ever get false, the entire data is garbage
        //
        auto const next_node = [&](TreeNode** node) -> bool
        {
            // assumption: index < data.size()

            size_t size = 0;
            cout << "next node from index " << index << "\n";

            for (; size < data.size() - index; ++size) {
                if (data[index+size] == ',') break;
                if (data[index+size] == ']') break;
            }
            if (index + size >= data.size()) {
                cout << " -> overlong size" << "\n";
                return false;
            }

            if (size == 4 && data.substr(index, size) == "null") {
                index += size + 1;
                *node = nullptr;
                cout << " -> node is a valid null\n";
                return true;
            }

            int value;
            auto [ptr_next, err] = std::from_chars(&data[index], &data[index+size], value);

            if (err != errc{} || ptr_next != &data[index+size]) {
                cout << " -> could not parse node data\n";
                return false;
            }
            cout << " -> found node with value " << value << "\n";

            index += size + 1;
            *node = new TreeNode{value};
            return true;
        };

        TreeNode* root;

        if (not next_node(&root)) {
            return nullptr;
        }

        auto queue = std::queue<TreeNode*>{};
        queue.push(root);

        while (index < data.size() && not queue.empty())
        {
            auto node = queue.front();
            queue.pop();

            if (not next_node(&node->left)) {
                // TODO: delete the tree
                return nullptr;
            }
            if (node->left != nullptr) {
                queue.push(node->left);
            }

            if (not next_node(&node->right)) {
                // TODO: delete the tree
                return nullptr;
            }
            if (node->right != nullptr) {
                queue.push(node->right);
            }
        }

        if (index != data.size()) {
            // TODO: delete the tree
            return nullptr;
        }

        return root;
    }

};
