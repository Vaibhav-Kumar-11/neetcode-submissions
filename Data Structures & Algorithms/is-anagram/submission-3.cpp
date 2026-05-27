class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        for(char c : t) freq[c - 'a']--;
        return freq == vector<int>(26, 0);
    }
};
