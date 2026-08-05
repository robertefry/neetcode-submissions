
class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        // assumption: heights.size() <= INT_MAX
        int i = 0;
        int j = heights.empty() ? 0 : heights.size() - 1;

        int max_area = 0;

        while (i < j)
        {
            // assumption: max_area <= INT_MAX
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
