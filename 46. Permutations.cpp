class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0)
            return vector<vector<int>>();

        if(nums.size() == 1)
            return vector<vector<int>>({nums});

        vector<vector<int>> res{};
        for(int i=0; i<nums.size(); i++) { 
            int p = nums.back();
            nums.pop_back();
            vector<vector<int>> perms = permute(nums);

            for(auto& perm: perms) {
                perm.push_back(p);
            }
            for(auto& p: perms) {
                res.push_back(p);
            }
            nums.insert(nums.begin(), p);
        }

        return res;

    }
};
