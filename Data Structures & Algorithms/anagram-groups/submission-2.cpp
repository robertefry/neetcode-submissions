
#include <numeric>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) // NOLINT
    {
        auto const to_key = [](string_view str) -> string
        {
            // TODO: Is there a better way to hash the strings?
            // assumption: Forall(c:str){ 'a' <= c <= 'z' }

            auto counts = array<size_t,26>{};
            for (char const chr : str) {
                counts[chr-'a'] += 1;
            }

            auto result = string{};
            for (size_t i = 0; i < counts.size(); ++i) {
                result += ',' + to_string(counts[i]);
            }
            return result;
        };

        auto groups = unordered_map<string,vector<string>>{};
        for (auto const& str : strs) {
            groups[to_key(str)].push_back(str);
        }

        auto result = vector<vector<string>>{};
        for (auto const& [_key,group] : groups) {
            result.push_back(group);
        }
        return result;
    }
};
