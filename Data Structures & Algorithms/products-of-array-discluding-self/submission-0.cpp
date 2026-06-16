class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> right(nums.size(),1);

        int lt=1, rt=1;
        
        for(int i=1; i<nums.size(); i++){
            lt *= nums[i-1];
            left[i]=lt;
        }
        for(int i=nums.size()-2; i>=0; i--){
            rt *= nums[i+1];
            right[i]=rt;
        }

        vector<int>ans; 
        for(int i=0; i<nums.size(); i++){
            ans.push_back((left[i]*right[i]));
        }

        return ans;
    }
};
