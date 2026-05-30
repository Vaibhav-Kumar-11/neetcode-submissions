class Solution {
public:
    bool isPalindrome(string s) {
        string output;
        for(auto it:s){
            if(isalnum(it) && it!=' '){
                output += tolower(it);
            }
        }
        string reversed_output = output;
        reverse(reversed_output.begin(), reversed_output.end());
        return output == reversed_output;
    }
};
