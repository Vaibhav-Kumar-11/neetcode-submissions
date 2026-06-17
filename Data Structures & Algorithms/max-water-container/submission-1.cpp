class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0, area=0;
        int i=0, j=heights.size()-1;

        while(i<=j){
            area = (j-i) * min(heights[i],heights[j]);
            res = max(res,area);

            if(heights[i]<heights[j]){
                i++;
            }
            else j--;
        }
        return res;
    }
};
