
class Solution {
public:
    int countSubstrings(string s)
    {
        auto const n = s.size();
        auto count = n;

        for (size_t i = 1; i < s.size(); ++i)
        {
            bool has_even = s[i-1] == s[i];
            bool has_odd = true;

            if (has_even) {
                count += 1;
            }

            size_t j = 1;
            for (; j < min(i,n-i) && (has_even || has_odd); ++j)
            {
                has_even &= s[i-j-1] == s[i+j];
                has_odd &= s[i-j] == s[i+j];

                if (has_even) {
                    count += 1;
                }
                if (has_odd) {
                    count += 1;
                }
            }
            if (j < n-i) {
                has_odd &= (s[i-j] == s[i+j]);

                if (has_odd) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
