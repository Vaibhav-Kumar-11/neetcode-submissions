class Solution {
public:

    void solve(int ind, string& digits, vector<string>& mpp,vector<string>& ans, string& curr){
       
       if(ind == digits.size()){
        ans.push_back(curr);
        return;
       }


       int digit = digits[ind]-'0';

       for(auto it : mpp[digit]){
        curr.push_back(it);
        solve(ind+1,digits,mpp,ans,curr);
        curr.pop_back();
       }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mpp;
        vector<string> ans;
        if(digits.size()==0) return ans;
        string curr;
        mpp = {"","", "abc","def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};

        solve(0,digits, mpp, ans, curr);

        return ans;

    }
};
