
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        auto const m = text1.size();
        auto const n = text2.size();

        auto dp = vector<vector<int>>(m,vector<int>(n));

        dp[0][0] = (text1[0] == text2[0]) ? 1 : 0;

        for (auto i = 1; i < m; ++i) {
            dp[i][0] = (text1[i] == text2[0]) ? 1 : dp[i-1][0];
        }
        for (auto j = 1; j < n; ++j) {
            dp[0][j] = (text1[0] == text2[j]) ? 1 : dp[0][j-1];
        }

        for (auto i = 1; i < m; ++i)
            for (auto j = 1; j < n; ++j)
        {
            dp[i][j] = (text1[i] == text2[j]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);
        }

        return dp[m-1][n-1];
    }
};
