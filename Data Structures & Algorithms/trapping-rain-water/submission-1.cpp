class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;


        for(int i = 0;i<height.size();i++){
            int max_l = 0, max_r = 0;
            
            for(int j = 0; j <= i; j++){
                max_l = max(max_l, height[j]);
            }

            for(int j = i; j < height.size(); j++){
                max_r = max(max_r, height[j]);
            }

            water += max(0, min(max_l, max_r) - height[i]);
        }
        return water;
    }
};
 