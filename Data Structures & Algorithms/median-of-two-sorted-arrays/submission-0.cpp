class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0.0;
        int maxSize = nums1.size() + nums2.size();
        int curr = -1, prev = -1;
        int left = 0, right = 0;
        int count = 0;

        while(count <= maxSize / 2){
            prev = curr;
            if(left >= nums1.size())curr = nums2[right], right++;
            else if(right >= nums2.size())curr = nums1[left], left++;
            else if(nums1[left] <= nums2[right])curr = nums1[left], left++;
            else curr = nums2[right], right++;
            count++;
        }

        median = (maxSize % 2 == 0) ? (prev + curr)/2.0 : curr;

        return median;
    }
};
