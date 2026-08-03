class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int len = 1;
        int max_len = 1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] == nums[i-1])continue;
            else if(nums[i] == nums[i-1] + 1)len++;
            else len = 1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
