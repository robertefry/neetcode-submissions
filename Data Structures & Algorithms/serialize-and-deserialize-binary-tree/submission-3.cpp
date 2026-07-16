
#include <cstring>

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

        class NodeQueue {
            std::queue<TreeNode*> queue {};
            size_t num_nonnull_elements {};
        public:
            void push_back(TreeNode* node) {
                this->queue.push(node);
                if (node != nullptr)
                    this->num_nonnull_elements += 1;
            }
            auto pop_front() {
                auto node = this->queue.front();
                this->queue.pop();
                if (node != nullptr)
                    this->num_nonnull_elements -= 1;
                return node;
            }
            bool empty() const {
                return num_nonnull_elements == 0;
            }
        };

        auto queue = NodeQueue{};
        queue.push_back(root->left);
        queue.push_back(root->right);

        while (not queue.empty())
        {
            auto node = queue.pop_front();

            if (node == nullptr) {
                oss << ",null";
                continue;
            }

            oss << ',' << to_string(node->val);
            queue.push_back(node->left);
            queue.push_back(node->right);
        }

        oss << ']';
        return oss.str();
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
            if (index >= data.size()) {
                *node = nullptr;
                return true;
            }

            size_t size = 0;

            for (; size < data.size() - index; ++size) {
                if (data[index+size] == ',') break;
                if (data[index+size] == ']') break;
            }
            if (index + size >= data.size()) {
                return false;
            }

            if (size == 4 && data.substr(index, size) == "null") {
                index += size + 1;
                *node = nullptr;
                return true;
            }

            int value;
            auto [ptr_next, err] = std::from_chars(&data[index], &data[index+size], value);

            if (err != errc{} || ptr_next != &data[index+size]) {
                return false;
            }

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
