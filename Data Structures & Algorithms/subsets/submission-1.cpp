class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> level;
        sort(nums.begin(), nums.end());
        fn(result,level,nums,0);
        return result;
    }

    void fn(vector<vector<int>>& result, vector<int>& level, vector<int>& nums, int start){
        result.push_back(level);

        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i-1]==nums[i]) continue;

            level.push_back(nums[i]);
            fn(result,level,nums,i+1);
            level.pop_back();
        }
    }
};
