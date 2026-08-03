class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(auto &str : strs){
            int length = str.size();
            s += to_string(length) + '#' + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i = 0;

        while(i < s.size()){
            int length = 0;
            string temp = "";
            while(s[i] != '#'){
                temp = temp + s[i];
                i++;
            }
            i++; //skipping #
            length = stoi(temp);
            ans.push_back(s.substr(i,length));
            i += length;
        }

        return ans;
    }
};
