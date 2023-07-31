class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> r;
        vector<vector<int>> res;

        backtrack(nums, target, res, r, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& r, int i) {
        // change
        if(target == 0) {
            res.push_back(r);
            return;
        }
        if(target <= 0) {
            return;
        }
        // change
        int prev = -1;
        while(i < nums.size()) {
            if(nums[i] == prev) { // change
                i++;
                continue;
            }

            r.push_back(nums[i]);

            backtrack(nums, target - nums[i], res, r, i+1);

            r.pop_back();
            prev = nums[i]; //change

            i++;
        }
    }
};
