class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>max_l(height.size(),0);
        vector<int>max_r(height.size(),0);
        int water = 0;

        max_l[0] = height[0];
        max_r[height.size()-1] = height[height.size()-1];

        for(int i = 1;i<height.size();i++){
            max_l[i] = max(max_l[i-1], height[i]); 
        }

        for(int i = height.size()-2;i>=0;i--){
            max_r[i] = max(max_r[i+1], height[i]);
        }

        for(int i = 0;i<height.size();i++){
            water += min(max_l[i], max_r[i]) - height[i]; 
        }
        return water;
    }
};
