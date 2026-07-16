
class Solution {
public:
    vector<int> countBits(int n)
    {
        auto result = vector<int>(n+1);

        auto known = stack<tuple<int,int>>{};
        known.push({1,1});

        while (not known.empty())
        {
            auto const [i, count] = known.top();
            known.pop();

            if (i > n) {
                continue;
            }

            result[i] = count;
            known.push({i*2, count});
            known.push({i*2+1, count+1});
        }
        return result;
    }
};
