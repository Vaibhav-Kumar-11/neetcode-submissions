class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> level;
        int i = 0;
        fn(result, level, i, nums);
        return result;
    }

    void fn(vector<vector<int>>& result, vector<int>& level, int i, vector<int>& nums){
        if(i==nums.size()){
            result.push_back(level);
            return;
        }
        level.push_back(nums[i]);
        fn(result,level,i+1,nums);
        level.pop_back();
        fn(result,level,i+1,nums);
    }
};
