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

            while (j - i + 1 > k + max_count)
            {
                counts[s[i]-'A'] -= 1;
                i += 1;

                // We don't shrink max_count here because max_count denotes
                // the count of the most frequent character in the current
                // longest substring. We only increase it when we find a more
                // frequenct character in another window, whose length is
                // bounded above by max_length. Only when this window increases
                // do we need to check it's validity which max_count governs.
            }
            max_length = max(max_length, j - i + 1);
        }
        return max_length;
    }
};
