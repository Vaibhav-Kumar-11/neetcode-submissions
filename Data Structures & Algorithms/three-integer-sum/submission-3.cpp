class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res; 
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k] == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    int target_1 = nums[j];
                    int target_2 = nums[k];
                    while(j < k && nums[j] == target_1) j++;
                    while(j < k && nums[k] == target_2) k--;
                }
                else if(nums[i]+nums[j]+nums[k] < 0) j++;
                else k--;
            }
        }
        return res;
    }
};
