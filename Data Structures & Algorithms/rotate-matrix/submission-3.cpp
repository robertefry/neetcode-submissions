
#include <barrier>
#include <future>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        const auto n = matrix.size();
        auto sync = barrier{static_cast<ptrdiff_t>(n)};

        auto const task = [&](size_t i)
        {
            if (2*i < n) {
                swap(matrix[i], matrix[n-i-1]);
            }
            sync.arrive_and_wait();

            for (size_t j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        };

        auto futures = vector<future<void>>{};
        futures.reserve(n);

        for (size_t i = 0; i < n; ++i) {
            futures.push_back(async(task, i));
        }
        for (auto& future : futures) {
            future.get();
        }
    }
};
