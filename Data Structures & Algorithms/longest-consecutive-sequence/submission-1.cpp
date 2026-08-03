class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ans(nums.begin(), nums.end());

        int max_l = 0;
        int curr = 0;
        int length = 0;
        for(auto &num : nums){
            if(ans.find(num - 1) == ans.end()){
                curr = num;
                length = 1;
            }
            while(ans.find(curr + 1)!= ans.end()){
                curr++;
                length++;
            }
            max_l = max(max_l, length);
        }
        return max_l;
    }
};
