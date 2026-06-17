class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int area = 0;
        for(int i=0; i<heights.size()-1; i++){
            for(int j=i+1; j<heights.size(); j++){
                area = (j-i)* min(heights[i],heights[j]);
                res = max(res,area);
            }
        }
        return res;
    }
};
