class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());

        // int last = 0;
        for(int i=0; i<nums.size(); i++) {
            // if (nums[i] != last) {
                int left = i+1;
                int right = nums.size() - 1;
                int sum = 0;

                while(left<right) {
                    sum = nums[i] + nums[left] + nums[right];
                    if (sum==0) {
                        s.insert({nums[i], nums[left], nums[right]});
                        right--;
                        left++;
                    } else if(sum > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            // }
            // last = nums[i];
        }

        for(vector<int> v: s) {
            res.push_back(v);
        }
        return res;

        return res;
    }
};
