
class Solution {
public:
    bool isPalindrome(string s)
    {
        size_t i = 0;
        size_t j = s.size()-1;

        while (true)
        {
            while (i < s.size() && not isalnum(s[i])) { ++i; }
            while (j < s.size() && not isalnum(s[j])) { --j; }
            if (i >= j || j >= s.size()) { break; }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
