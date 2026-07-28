class Solution {
   public:
    // int max1 = 0;
    // void rob1(vector<int>& nums, int sum, int i) {
    //     max1 = max(sum, max1);
    //     if (i >= nums.size()) return;
    //     rob1(nums, sum + nums[i], i + 2);
    //     rob1(nums, sum, i + 1);
    // }
    int rob(vector<int>& nums) {
        // recursove solution
        vector<int> help(nums.size()+1,0);
        help[1] = nums[0];
        for(int i=2; i<=nums.size();i++){
            help[i] = max(help[i-1], help[i-2]+nums[i-1]);
        }
        return help[nums.size()];


    }
};
