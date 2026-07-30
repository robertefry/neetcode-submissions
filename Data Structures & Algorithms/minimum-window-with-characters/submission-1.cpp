


class Solution {
public:
    string minWindow(string s, string t)
    {
        // 1. Count the frequency of characters in t.

        auto t_counts = accumulate(
            t.begin(),
            t.end(),
            unordered_map<char,size_t>{},
            [](auto counts, char c) { counts[c] += 1; return counts; }
        );

        // 2. Find the first substring of s containing all characters of t by
        // counting the frequency of characters and comparing against t_counts.

        auto s_counts = unordered_map<char,size_t>{};
        size_t i = 0;
        size_t j = 0;

        for (; j < s.size(); ++j)
        {
            if (not t_counts.contains(s[j])) {
                continue;
            }
            s_counts[s[j]] += 1;

            if (ranges::all_of(t_counts, [&](auto const& pair) {
                return s_counts[pair.first] >= pair.second;
            })) {
                break;
            }
        }

        if (j == s.size()) {
            // A substring of s containing all characters of t does not exist.
            return "";
        }

        for (; i < j; ++i)
        {
            if (not t_counts.contains(s[i])) {
                continue;
            }
            if (s_counts[s[i]] == t_counts[s[i]]) {
                break;
            }
            s_counts[s[i]] -= 1;
        }

        auto substr = string_view{s.data() + i, j-i+1};

        // 3. After each time we find a new substring, increment i until we
        // remove one necessary character and re-find the next substring.

        while (j < s.size())
        {
            s_counts[s[i]] -= 1;
            i += 1;
            j += 1;

            for (; j < s.size(); ++j)
            {
                if (not t_counts.contains(s[j])) {
                    continue;
                }
                s_counts[s[j]] += 1;

                if (s[j] == s[i-1]) {
                    break;
                }
            }
            if (j == s.size()) {
                break;
            }

            for (; i < j; ++i)
            {
                if (not t_counts.contains(s[i])) {
                    continue;
                }
                if (s_counts[s[i]] == t_counts[s[i]]) {
                    break;
                }
                s_counts[s[i]] -= 1;
            }

            substr = min(
                substr,
                string_view{s.data() + i, j-i+1},
                [](auto const& a, auto const& b) { return a.size() < b.size(); }
            );
        }

        return string{substr};
    }
};
