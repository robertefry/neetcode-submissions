
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }
        auto const n = s.size();

        auto s_counts = unordered_map<char,size_t>{};
        auto t_counts = unordered_map<char,size_t>{};

        for (size_t i = 0; i < n; ++i) {
            s_counts[s[i]] += 1;
            t_counts[t[i]] += 1;
        }

        return s_counts == t_counts;
    }
};
