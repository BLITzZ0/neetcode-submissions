class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;

        int left = 0, right = 0;
        int max_size = 0;
        
        while(right < s.size()){
            if(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }else{
                st.insert(s[right]);
                right++;
            }
            max_size = max(max_size, right - left);
        }

        return max_size;
    }
};
