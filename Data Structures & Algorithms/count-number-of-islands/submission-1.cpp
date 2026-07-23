
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        // assumption: Forall(i,j){ grid[i].size() == grid[j].size() }
        auto const n = grid.size();
        auto const m = (n == 0) ? 0 : grid[0].size();

        auto stack = std::stack<tuple<size_t,size_t>>{};
        int num_islands = 0;

        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < m; ++j)
        {
            if (grid[i][j] != '1') {
                continue;
            }

            num_islands += 1;
            stack.push({i,j});

            while (not stack.empty())
            {
                auto const [i,j] = stack.top();
                stack.pop();

                // invariant: grid[i][j] == '1'

                grid[i][j] = '0';
                if (i+1 < n && grid[i+1][j] == '1') stack.push({i+1,j});
                if (i >= 1  && grid[i-1][j] == '1') stack.push({i-1,j});
                if (j+1 < m && grid[i][j+1] == '1') stack.push({i,j+1});
                if (j >= 1  && grid[i][j-1] == '1') stack.push({i,j-1});
            }
        }
        return num_islands;
    }
};
