
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0;
        int j = 0;

        auto found = unordered_set<char>{};
        int max_substr = 0;

        for (; j < s.size(); ++j)
        {
            if (not found.contains(s[j])) {
                found.insert(s[j]);
                continue;
            }
            max_substr = max(max_substr, j-i);

            for (++i; s[i-1] != s[j]; ++i) {
                found.erase(s[i-1]);
            }
        }
        return max(max_substr, j-i);
    }
};
