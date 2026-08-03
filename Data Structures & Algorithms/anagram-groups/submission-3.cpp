class Solution {
public:
    string calculateHash(string str){
        vector<int>freq(26,0);
        string res= "";
        for(auto &s : str){
            freq[s - 'a']++;
        }

        for(auto &f : freq){
            res += "#" + to_string(f);
        }

        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;
        for(auto &s : strs){
            string temp = calculateHash(s);
            mp[temp].push_back(s);
        }
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
