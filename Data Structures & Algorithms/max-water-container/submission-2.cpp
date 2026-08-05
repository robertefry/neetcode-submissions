
class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        size_t i = 0;
        size_t j = heights.empty() ? 0 : heights.size() - 1;

        int max_area = 0;

        while (i < j)
        {
            int area = min(heights[j], heights[i]) * (j-i);
            max_area = max(max_area, area);

            if (heights[i] < heights[j]) {
                i += 1;
            } else {
                j -= 1;
            }
        }
        return max_area;
    }
};
