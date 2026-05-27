class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for(int i=0; i<=n; i++){
            int temp = i;
            int cnt=0;
            while(temp>0){
                temp = temp & (temp-1);
                cnt++;
            }
            if(i==0) output.push_back(0);
            else output.push_back(cnt);
        }
        return output;
    }
};
