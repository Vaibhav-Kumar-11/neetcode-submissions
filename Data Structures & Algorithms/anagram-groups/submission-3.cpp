class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(auto& it:strs){
            string key = it;
            sort(key.begin(),key.end());
            mpp[key].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto& [key,group]:mpp){
            ans.push_back(group);
        }
        return ans;
    }
};
