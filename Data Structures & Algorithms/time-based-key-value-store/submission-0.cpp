#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;


class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())return "";

        int left = 0, right = mp[key].size() - 1;
        int ans = -1;

        auto &v = mp[key];

        while(left <= right){
            int mid = left + (right - left)/2;
            if(v[mid].first <= timestamp){
                ans = mid;
                left = mid + 1;
            }else right = mid - 1;
        }

        if(ans == -1)return "";
        return v[ans].second;
    }
};

// int main(){
//     TimeMap tm;
//     tm.set("Abhishek", "Happy", 1);
//     cout<<tm.get("Abhishek", 1);
// }
