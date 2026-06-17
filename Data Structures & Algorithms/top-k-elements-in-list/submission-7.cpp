class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto& it:nums){
            mpp[it]++;
        }
        // {el,fre} store hogya h mpp mei

        vector<vector<int>> bucket(nums.size()+1);
        for(auto [el,freq]:mpp){
            bucket[freq].push_back(el);
        }
        vector<int>ans;

        for(int i=bucket.size()-1; i>=0; i--){
            for(auto it:bucket[i]){
                ans.push_back(it);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
