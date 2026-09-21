class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int windowSum = 0;
        int n = nums.size();
        for(int i =0 ; i< k ; i++){
            windowSum += nums[i];
        }
        int maxsum = windowSum;
        for(int i =k ; i<n;i++){
            windowSum += nums[i];
            windowSum -= nums[i-k];
         maxsum = max(maxsum, windowSum);
        }
        return (double)maxsum / k;
    }
};