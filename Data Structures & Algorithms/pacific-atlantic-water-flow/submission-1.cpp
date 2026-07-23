
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        // assumption: Forall(i){ heights[i].size() == heights[j].size() }
        size_t const m = heights.size();
        size_t const n = (m == 0) ? 0 : heights[0].size();

        auto const reachable = [&](function<bool(size_t,size_t)> const& seed)
        {
            auto cells = stack<tuple<size_t,size_t>>{};

            for (size_t i = 0; i < m; ++i)
                for (size_t j = 0; j < n; ++j)
                    if (seed(i,j))
            {
                cells.push({i,j});
            }

            auto reachable = vector(m,vector(n,false));
            auto seen = vector(m,vector(n,false));

            while (not cells.empty())
            {
                auto const [i,j] = cells.top();
                cells.pop();

                if (seen[i][j]) continue;
                seen[i][j] = true;

                reachable[i][j] = true;
                if (i+1 < m && heights[i+1][j] >= heights[i][j]) cells.push({i+1,j});
                if (i >= 1  && heights[i-1][j] >= heights[i][j]) cells.push({i-1,j});
                if (j+1 < n && heights[i][j+1] >= heights[i][j]) cells.push({i,j+1});
                if (j >= 1  && heights[i][j-1] >= heights[i][j]) cells.push({i,j-1});
            }
            return reachable;
        };

        auto const can_reach_pacific = reachable([](auto i, auto j) {
            return i == 0 || j == 0;
        });
        auto const can_reach_atlantic = reachable([&](auto i, auto j) {
            return i+1 == m || j+1 == n;
        });

        auto watershed_divides = vector<vector<int>>{};

        for (size_t i = 0; i < m; ++i)
            for (size_t j = 0; j < n; ++j)
                if (can_reach_pacific[i][j] && can_reach_atlantic[i][j])
        {
            watershed_divides.push_back({static_cast<int>(i),static_cast<int>(j)});
        }
        return watershed_divides;
    }
};
