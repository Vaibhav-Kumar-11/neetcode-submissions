class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: count frequency of each element
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        // Step 2: create buckets where index = frequency
        // bucket[3] = all elements that appear exactly 3 times
        vector<vector<int>> bucket(n + 1);
        for (auto& [element, freq] : mpp) {
            bucket[freq].push_back(element);
        }

        // Step 3: go from highest freq to lowest, pick k elements
        vector<int> res;
        for (int i = n; i >= 1; i--) {
            for (int element : bucket[i]) {
                res.push_back(element);
                if (res.size() == k) {
                    return res;   // got our k elements, stop early
                }
            }
        }

        return res;
    }
};