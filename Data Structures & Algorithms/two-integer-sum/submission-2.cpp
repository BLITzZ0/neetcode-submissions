class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>ans = {0,0};
        // int left = 0, right = 0;
        for(int i = 0;i<nums.size();i++){
            int need = target - nums[i];
            if(mp.find(need)!=mp.end()){
                if(i > mp[need])ans[0] = mp[need], ans[1] = i;
                else ans[0] = i, ans[1] = mp[need];
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};
