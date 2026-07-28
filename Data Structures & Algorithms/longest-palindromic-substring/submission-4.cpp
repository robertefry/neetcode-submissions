
class Solution {
public:
    string longestPalindrome(string const& s)
    {
        auto const n = s.size();
        auto best = tuple<size_t,size_t>{0,0};

        auto const make_best = [&](tuple<size_t,size_t> candidate) {
            if (get<1>(best) - get<0>(best) < get<1>(candidate) - get<0>(candidate)) {
                best = std::move(candidate);
            }
        };

        for (size_t i = 1; i < s.size(); ++i)
        {
            bool has_even = s[i-1] == s[i];
            bool has_odd = true;

            if (has_even) {
                make_best({i-1, i});
            }

            size_t j = 1;

            // 0 <= i-j-1 < i-j <= i+j < n  <=>  j < min(i,n-i)
            for (; j < min(i,n-i) && (has_even || has_odd); ++j)
            {
                has_even &= (s[i-j-1] == s[i+j]);
                has_odd &= (s[i-j] == s[i+j]);

                if (has_even) {
                    make_best({i-j-1, i+j});
                }
                if(has_odd) {
                    make_best({i-j, i+j});
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
                    make_best({i-j, i+j});
                }
            }
        }

        return s.substr(get<0>(best), get<1>(best) - get<0>(best) + 1);
    }
};
