class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ans(nums.begin(), nums.end());

        int max_l = 0;
        for(auto &num : nums){
           if(ans.find(num - 1) == ans.end()){
            int curr = num;
            int len = 1;

            while(ans.find(curr + 1) != ans.end()){
                curr++;
                len++;
            }
            max_l = max(max_l, len);
           }
        }
        return max_l;
    }
};
