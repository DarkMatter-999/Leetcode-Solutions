class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        // set<vector<int>> s;
        sort(nums.begin(), nums.end());

        for(int k=0; k<nums.size(); k++) {
            if(k>0 && nums[k] == nums[k-1]) continue;
            for(int i=k+1; i<nums.size(); i++) {
                if(i>k+1 && nums[i] == nums[i-1]) continue;
                int left = i+1;
                int right = nums.size() - 1;
                long long sum = 0;

                while(left<right) {
                    // INT fuck you
                    sum = nums[k];
                    sum += nums[i];
                    sum += nums[left];
                    sum += nums[right];
                    if (sum==target) {
                        vector<int> temp = {nums[k], nums[i], nums[left], nums[right]};
                        res.push_back(temp);

                        right--;
                        left++;
                        while(right>left && nums[left] == nums[left-1]) left++;
                        while(right>left && nums[right] == nums[right+1]) right--;
                    } else if(sum > target) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        // for(vector<int> v: s) {
        //     res.push_back(v);
        // }
        return res;
    }
};
