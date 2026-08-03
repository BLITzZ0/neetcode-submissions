class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<pair<int, int>>p;
        vector<int>ans;
        for(auto &i : nums){
            mp[i]++;
        }

        for(auto &it : mp){
            p.push_back(it);
        }

        sort(p.begin(), p.end(),[] (auto &a, auto &b){
            return a.second > b.second;
        });

        for(int i = 0;i<k;i++){
            ans.push_back(p[i].first);
        }

        return ans;

    }
};
