class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, r = 0;
        int maxSum = nums[0], currSum = 0;

        for(int i=0; i<nums.size(); i++) {
            if(currSum < 0) currSum = 0;

            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
