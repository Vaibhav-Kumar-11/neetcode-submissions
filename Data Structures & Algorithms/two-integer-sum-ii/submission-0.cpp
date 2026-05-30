class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //1 based indexing and to return indices
        int st=0;
        int en=numbers.size()-1;

        while(st<en){
            if(numbers[st]+numbers[en] == target){
                return {st+1,en+1};
            }
            if(numbers[st]+numbers[en] > target){
                en--;
            }
            else{
                st++;
            }
        }
        return {};
    }
};
