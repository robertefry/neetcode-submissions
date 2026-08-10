class Solution {
public:
    int characterReplacement(string s, int k)
    {
        // assumption: Forall(i){ s[i] in 'A'..='Z' }
        auto counts = array<size_t,26>{};

        size_t max_count = 0;
        size_t max_length = 0;

        size_t i = 0;
        size_t j = 0;

        for (; j < s.size(); ++j)
        {
            counts[s[j]-'A'] += 1;
            max_count = max(max_count, counts[s[j]-'A']);

            while (j - i + 1 - max_count > k)
            {
                counts[s[i]-'A'] -= 1;
                i += 1;
            }
            max_length = max(max_length, j - i + 1);
        }
        return max_length;
    }
};
