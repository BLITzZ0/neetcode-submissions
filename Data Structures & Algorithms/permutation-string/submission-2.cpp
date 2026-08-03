class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;
        vector<int>s1_freq(26, 0);
        vector<int>s2_freq(26,0);

        int left = 0, right = s1.size()-1;

        for(auto &s : s1)s1_freq[s - 'a']++;
        for(int i = 0;i<=right;i++){
            s2_freq[s2[i] - 'a']++;
        }

        if(s1_freq == s2_freq)return true;

        while(right + 1 < s2.size()){
            s2_freq[s2[left] - 'a']--;
            left++, right++;
            s2_freq[s2[right] - 'a']++;
            if(s1_freq == s2_freq){
                return true;
            } 
        }
        return false;
    }
};
