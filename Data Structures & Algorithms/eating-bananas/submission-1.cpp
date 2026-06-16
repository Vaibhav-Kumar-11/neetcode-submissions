class Solution {
private:
    void time_req(int& ans, int& t, vector<int>& piles){
        for(auto it:piles){
            ans += (it+t-1)/t;
        }
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(),piles.end());

        int res=0;
        while(low<=high){
            int ans = 0;
            int mid = low + (high-low)/2;

            time_req(ans,mid,piles);
            if(ans<=h){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};
