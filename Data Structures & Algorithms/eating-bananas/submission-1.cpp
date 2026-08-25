class Solution {
public:
    int pilesToEat(vector<int> &piles, int mid){
        int res = 0;
        for(int i = 0; i < piles.size();i++){
            res += (piles[i] + mid - 1) / mid;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int k = pilesToEat(piles, mid);
            if(k <= h){
                ans = mid;
                right = mid - 1;
            }
            else if(k > h)left = mid + 1;
        }

        return ans;
    }
};
