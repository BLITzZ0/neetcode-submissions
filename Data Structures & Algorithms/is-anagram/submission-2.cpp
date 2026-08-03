class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())return false;
        
        unordered_map<char, int>mps;
        unordered_map<char, int>mpt;

        for(auto c : s){
            mps[c]++;
        }

        for(auto c : t){
            mpt[c]++;
        }

        for(auto c : s){
            if(mpt[c] != mps[c])return false;
        }

        return true;
    }
};
