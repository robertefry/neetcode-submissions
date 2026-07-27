
struct TrieNode {
    unordered_map<char,unique_ptr<TrieNode>> subnodes {};
    bool terminal = false;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
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
                if (not node->subnodes.contains(chr)) {
                    node->subnodes.insert({chr, make_unique<TrieNode>()});
                }
                node = node->subnodes.at(chr).get();
            }
            node->terminal = true;
        }

        // 2. If our dictionary contains the empty word, we should always find that on the board.

        auto found = unordered_set<string>{};

        if (trie.terminal) {
            found.insert(string{});
        }

        // 3. DFS through the board adding words as we find them in the dictionary.

        struct seen_hasher {
            size_t operator()(tuple<size_t,size_t> const& data) const {
                // FIXME: This needs securing. But it's good enough for now.
                return hash<size_t>{}(get<0>(data)) xor hash<size_t>{}(get<1>(data));
            }
        };

        auto word_builder = string{};
        auto seen = unordered_set<tuple<size_t,size_t>, seen_hasher>{};

        auto const dfs = [&](this auto&& dfs, TrieNode const* parent, size_t i, size_t j)
        {
            if (i >= m or j >= n) {
                return; // out of bounds
            }
            if (seen.contains({i,j})) {
                return; // cell already visited
            }
            if (not parent->subnodes.contains(board[i][j])) {
                return; // cell isn't in the trie dictionary
            }

            auto const node = parent->subnodes.at(board[i][j]).get();

            seen.insert({i,j});
            word_builder.push_back(board[i][j]);

            if (node->terminal) {
                found.insert(word_builder);
            }

            dfs(node, i+1, j);
            dfs(node, i-1, j);
            dfs(node, i, j+1);
            dfs(node, i, j-1);

            word_builder.pop_back();
            seen.erase({i,j});
        };

        for (size_t i = 0; i < m; ++i)
            for (size_t j = 0; j < n; ++j)
        {
            dfs(&trie, i, j);
        }

        // 4. Return the list of found words.

        auto found_words = vector<string>{};

        for (auto&& word : move(found)) {
            found_words.push_back(move(word));
        }

        return found_words;
    }
};
