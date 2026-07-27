
class Solution {

    // since we're not using the trie anywhere else, we'll hijack the terminal
    // flag to determine if the word has already been found in another dfs
    struct TrieNode {
        // TODO: cache sequences of nodes
        array<unique_ptr<TrieNode>,26> subnodes;
        enum { PARTIAL, TERMINAL, FOUND } state = PARTIAL;

        auto at(this auto&& self, char chr) -> decltype(auto) {
            return forward<decltype(self)>(self).subnodes[chr-'a'];
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        // assumption: Forall(i,j){ words[i][j] in 'a'..='z' }

        // assumption: Forall(i,j){ board[i].size() == board[j].size() }
        size_t const m = board.size();
        size_t const n = (m == 0) ? 0 : board[0].size();

        // 1. Construct a Trie of our dictionary of words.

        auto trie = TrieNode{};

        for (auto const& word : words)
        {
            TrieNode* node = &trie;

            for (char chr : word)
            {
                if (node->at(chr) == nullptr) {
                    node->at(chr) = make_unique<TrieNode>();
                }
                node = node->at(chr).get();
            }
            node->state = TrieNode::TERMINAL;
        }

        // 2. If our dictionary contains the empty word, we should always find that on the board.

        auto found = vector<string>{};
        found.reserve(words.size());

        if (trie.state == TrieNode::TERMINAL) {
            found.push_back(string{});
            trie.state = TrieNode::FOUND;
        }

        // 3. DFS through the board adding words as we find them in the dictionary.

        auto word_builder = string{};
        auto seen = vector<vector<bool>>(m, vector<bool>(n, false));

        auto const dfs = [&](this auto&& dfs, TrieNode const* parent, size_t i, size_t j)
        {
            if (i >= m or j >= n) {
                return; // out of bounds
            }
            if (seen[i][j]) {
                return; // cell already visited
            }
            if (parent->at(board[i][j]) == nullptr) {
                return; // cell isn't in the trie dictionary
            }

            auto const node = parent->at(board[i][j]).get();

            seen[i][j] = true;
            word_builder.push_back(board[i][j]);

            if (node->state == TrieNode::TERMINAL) {
                found.push_back(word_builder);
                node->state = TrieNode::FOUND;
            }

            dfs(node, i+1, j);
            dfs(node, i-1, j);
            dfs(node, i, j+1);
            dfs(node, i, j-1);

            word_builder.pop_back();
            seen[i][j] = false;
        };

        for (size_t i = 0; i < m; ++i)
            for (size_t j = 0; j < n; ++j)
        {
            dfs(&trie, i, j);
        }

        // 4. Return the list of found words.

        return found;
    }
};
