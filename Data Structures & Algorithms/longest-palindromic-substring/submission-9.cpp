
class Solution {
public:
    string longestPalindrome(string const& s)
    {
        auto const n = s.size();
        auto best = tuple<size_t,size_t>{0, n == 0 ? 0 : 1};

        constexpr auto make_best = [](tuple<size_t,size_t>&& best, size_t begin, size_t size) static {
            if (get<1>(best) < size) {
                return make_tuple(begin, size);
            }
            return std::move(best);
        };

        for (size_t i = 1; i < s.size(); ++i)
        {
            bool has_even = s[i-1] == s[i];
            bool has_odd = true;

            if (has_even) {
                best = make_best(std::move(best), i-1, 2);
            }

            size_t j = 1;

            // 0 <= i-j-1 < i-j <= i+j < n  <=>  j < min(i,n-i)
            for (; j < min(i,n-i) && (has_even || has_odd); ++j)
            {
                has_even &= (s[i-j-1] == s[i+j]);
                has_odd &= (s[i-j] == s[i+j]);

                if (has_even) {
                    best = make_best(std::move(best), i-j-1, 2*j+2);
                }
                if(has_odd) {
                    best = make_best(std::move(best), i-j, 2*j+1);
                }
            }
            //  j == min(i,n-i)  =>  {
            //      j == i  <=>  i-j-1 < 0 <= i-j <= i+j
            //  } or {
            //      j == n-i  <=>  j+i == n
            //  }
            if (j < n-i) {
                has_odd &= (s[i-j] == s[i+j]);

                if (has_odd) {
                    best = make_best(std::move(best), i-j, 2*j+1);
                }
            }
        }

        return s.substr(get<0>(best), get<1>(best));
    }
};
