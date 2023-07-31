class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> r;
        vector<vector<int>> res;

        backtrack(nums, target, res, r, 0);

        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& r, int i) {
        if(target == 0) {
            res.push_back(r);
            return;
        }

        while(i < nums.size() && (target - nums[i]) >= 0) {
            r.push_back(nums[i]);

            backtrack(nums, target - nums[i], res, r, i);
            i++;

            r.pop_back();
        }
    }
};
