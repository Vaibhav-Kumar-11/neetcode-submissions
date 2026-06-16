class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }

        vector<vector<int>> arr(nums.size()+1);
        for(auto [el,freq]:mpp){
            arr[freq].push_back(el);
        }
        
        vector<int> ans;
        for(int i=arr.size()-1; i>=0; i--){
            for(auto it:arr[i]){
                ans.push_back(it);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};


