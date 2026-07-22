
class PrefixTree
{
    // assumption: all words contain characters in 'a'..='z'

    struct Node {
        array<unique_ptr<Node>,26> nodes {};
        bool is_end = false;
    };

    Node root {};

public:
    PrefixTree() = default;

    void insert(string word)
    {
        if (word.empty()) {
            root.is_end = true;
            return;
        }

        Node* node = &root;

        for (char c : word)
        {
            if (node->nodes[c-'a'] == nullptr) {
                node->nodes[c-'a'] = make_unique<Node>();
            }
            node = node->nodes[c-'a'].get();
        }
        node->is_end = true;
    }

    bool search(string word)
    {
        if (word.empty()) {
            return root.is_end;
        }

        Node* node = &root;

        for (char c : word)
        {
            if (node->nodes[c-'a'] == nullptr) {
                return false;
            }
            node = node->nodes[c-'a'].get();
        }
        return node->is_end == true;
    }

    bool startsWith(string prefix)
    {
        if (prefix.empty()) {
            return root.is_end;
        }

        Node* node = &root;

        for (char c : prefix)
        {
            if (node->nodes[c-'a'] == nullptr) {
                return false;
            }
            node = node->nodes[c-'a'].get();
        }
        return true;
    }
};
