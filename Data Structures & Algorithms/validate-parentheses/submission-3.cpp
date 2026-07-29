
class Solution {
public:
    bool isValid(string s)
    {
        constexpr auto pairs = array{
            tuple{'(', ')'},
            tuple{'{', '}'},
            tuple{'[', ']'},
            tuple{'<', '>'},
        };

        // TODO: make these static-initialized (thread-safe) for future invocations
        auto openers = unordered_set<char>(pairs.size());
        auto closers = unordered_map<char,char>(pairs.size());

        for (auto const [ open, close ] : pairs) {
            openers.emplace(open);
            closers.emplace(close, open);
        }

        auto opened = stack<char>{};

        for (char const c : s) {
            if (openers.contains(c)) {
                opened.push(c);
                continue;
            }
            if (closers.contains(c)) {
                if (opened.empty() || opened.top() != closers.at(c)) {
                    return false;
                }
                opened.pop();
                continue;
            }
            // otherwise ignored
        }

        return opened.empty();
    }
};
