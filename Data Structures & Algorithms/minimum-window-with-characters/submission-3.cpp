/*
Minimum Window Substring
Hard
Topics
Company Tags
Hints
Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

You may assume that the correct output is always unique.

Example 1:

Input: s = "OUZODYXAZV", t = "XYZ"

Output: "YXAZ"
Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.

Example 2:

Input: s = "xyz", t = "xyz"

Output: "xyz"
Example 3:

Input: s = "x", t = "xy"

Output: ""
Constraints:

1 <= s.length <= 1000
1 <= t.length <= 1000
s and t consist of uppercase and lowercase English letters
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string minWindow(string s, string t){
        if(s.size() < t.size())return "";

        vector<int>t_freq(128, 0);
        vector<int>s_freq(128, 0);

        int required = 0;
        int formed = 0;

        for(auto &c : t){
            if(t_freq[c] == 0)required++;

            t_freq[c]++;
        }

        int minLength = INT_MAX;
        string ans = "";

        int left = 0, right = 0;
        while(right < s.size()){
            char ch = s[right];

            s_freq[ch]++;
            if(s_freq[ch] == t_freq[ch]){
                formed++;
            }

            while(formed == required){
                int currLength = right - left + 1;

                if(currLength < minLength){
                    ans = s.substr(left, right - left + 1);
                    minLength = currLength;
                }

                s_freq[s[left] ]--;

                if(s_freq[s[left]] < t_freq[s[left]]){
                    formed--;
                }

                left++;

            }
            right++;
        }
        return ans;
    }
};

// int main(){
//     Solution s;
//     cout<<s.minWindow("OUZODYXAZV", "XYZ")<<endl;
//     cout<<s.minWindow("xyz", "xyz")<<endl;
//     cout<<s.minWindow("x", "xy")<<endl;
//     cout<<s.minWindow("a", "b")<<endl;
// }