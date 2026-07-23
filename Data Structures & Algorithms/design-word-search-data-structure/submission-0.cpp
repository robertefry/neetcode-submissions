
class WordDictionary
{
    // assumption: all words consist of characters in 'a'..='z'

    struct TrieNode {
        array<unique_ptr<TrieNode>,26> nodes;
        bool terminal;
    };

    TrieNode root;

public:
    WordDictionary() = default;

    void addWord(string word)
    {
        TrieNode* node = &root;

        for (char c : word) {
            if (node->nodes[c-'a'] == nullptr) {
                node->nodes[c-'a'] = make_unique<TrieNode>();
            }
            node = node->nodes[c-'a'].get();
        }
        node->terminal = true;
    }

    bool search(string word) const
    {
        auto stack = std::stack<tuple<TrieNode const*, size_t>>{};
        stack.push({&root, 0});

        while (not stack.empty())
        {
            auto const [node, index] = stack.top();
            stack.pop();

            // invariant: index <= word.size()

            // if the node is nullptr, the character at this index does not
            // exist in the trie. so we backtrack.
            if (node == nullptr) {
                continue; // backtrack
            }

            // if we're at the end of the word, we've found all characters in
            // the word. so return true if we also have the terminal.
            if (index == word.size()) {
                return node->terminal;
            }

            // handle wildcards by allowing it to represent all characters the
            // trie has at this node.
            if (word[index] == '.') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    stack.push({node->nodes[c-'a'].get(), index+1});
                }
                continue;
            }

            // TODO: we can probably optimise this a little and only push
            // when we reach a branch point (i.e. a wildcard character)
            stack.push({node->nodes[word[index]-'a'].get(), index+1});
        }

        return false;
    }
};
