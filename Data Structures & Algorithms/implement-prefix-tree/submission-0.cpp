
class PrefixTree
{
    // assumption: all words contain characters in 'a'..='z'

    struct Node {
        Node* nodes[26]{};
        bool is_end;
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
                node->nodes[c-'a'] = new Node{};
            }
            node = node->nodes[c-'a'];
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
            node = node->nodes[c-'a'];
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
            node = node->nodes[c-'a'];
        }
        return true;
    }
};
