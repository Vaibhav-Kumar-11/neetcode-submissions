class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TC = O(N(traversing) + NlogN{push in heap} + KlogN{pop from heap}) ~ O(NlogN)
        // SC = O(N{map} + N{pq} + k{result}) ~ O(N)
        unordered_map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto& [el,freq] : mpp){
            pq.push({freq,el});
        }

        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};