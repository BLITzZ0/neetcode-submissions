class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size() - 1;
        vector<int>ans;

        for(int i = 0;i <= size - k + 1;i++){
            int max_e = nums[i];
            for(int j = i;j<i + k;j++){
                max_e = max(max_e, nums[j]);
            }
            ans.push_back(max_e);
        }
        return ans;
    }
};
