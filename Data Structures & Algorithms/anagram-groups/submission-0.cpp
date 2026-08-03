class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_s;

        for(auto &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            if(map_s.find(temp)!=map_s.end()){
                map_s[temp].push_back(s);
            }
            else map_s[temp].push_back(s);
        }
        vector<vector<string>>ans;

        for(auto it = map_s.begin(); it != map_s.end();it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};
