class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int need = 0 - nums[i];
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                
                long long sum =1LL * nums[left] + nums[right];

                if(sum == need){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++, right--;

                    while(left < right && nums[left] == nums[left - 1])left++;
                    while(left < right && nums[right] == nums[right + 1])right--;
                }
                
                else if(sum > need)right--;
                else left++;
            }
        }
        return ans;

    }
};
